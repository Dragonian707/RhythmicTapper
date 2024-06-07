#include <fstream>
#include <sstream>

#include "level1scene.h"



Level1Scene::Level1Scene(float os, std::string music) : Level(os)
{
	leveltrack = ResourceManager::Instance()->GetMusic(music);
	leveltrack.loopCount = 1;
	PlayMusicStream(leveltrack);
	activescene = 2;
	offset = os;

	bg = new Background("assets/background1.png");
	bg->position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2);
	bg->color = BLACK;
	AddObject(bg);

	text = new TextSprite();
	text->position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2);
	text->SetMessage("");
	text->scale = 5.0f;
	AddObject(text);

	light1 = new IndicatorLight(LIME);
	light1->position = Vector2(SCRWIDTH / 2 - 75, SCRHEIGHT / 4 * 3);
	light1->color = LIME;
	lights.push_back(light1);
	objects.push_back(light1);

	light2 = new IndicatorLight(GREEN);
	light2->position = Vector2(SCRWIDTH / 2 - 25, SCRHEIGHT / 4 * 3);
	light2->color = GREEN;
	lights.push_back(light2);
	objects.push_back(light2);

	light3 = new IndicatorLight(ORANGE);
	light3->position = Vector2(SCRWIDTH / 2 + 25, SCRHEIGHT / 4 * 3);
	light3->color = ORANGE;
	lights.push_back(light3);
	objects.push_back(light3);

	light4 = new IndicatorLight(RED);
	light4->position = Vector2(SCRWIDTH / 2 + 75, SCRHEIGHT / 4 * 3);
	light4->color = RED;
	lights.push_back(light4);
	objects.push_back(light4);

	light5 = new IndicatorLight(BLACK);
	light5->position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 4 * 3 - 50);
	light5->color = BLACK;
	lights.push_back(light5);
	objects.push_back(light5);

	Setuppulses();
}

Level1Scene::~Level1Scene()
{
	for (DrawSprite* o : objects)
	{
		DeleteObject(o);
	}
}

void Level1Scene::update(float deltaTime)
{
	if (IsKeyPressed(KEY_BACKSPACE)) //Can't use escape sadly, too much input delay
	{
		CloseGame();
	}

	if (!ready)
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			ready = true;
			for (DrawSprite* o : objects)
			{
				AddObject(o);
			}
		}
		return;
	}


	timer += deltaTime;
	UpdateMusicStream(leveltrack);
	CheckHits();

	if (IsKeyPressed(KEY_R))
	{
		PauseMusicStream(leveltrack);
		RestartLevel(leveltrack);
		for (DrawSprite* o : objects)
		{
			RemoveObject(o);
		}
		Setuppulses();
		timer = 0;
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		text->SetMessage(std::to_string(misses));
	}

	if (pulses.size() <= 0) { return; }

	if (timer >= pulses[0].x)
	{
		SendPulse(pulses[0].y);
		pulses.erase(pulses.begin());
	}
}

void Level1Scene::CheckHits()
{
	if (currentToHit >= toHit.size()) { text->SetMessage(CalculateGrade()); bg->Change(DARKGRAY); return; }
	if (toHit[currentToHit] - timer > 0.5f) { return; }
	if (toHit[currentToHit] - timer < -0.5f) { currentToHit++; misses++; return; }

	if (IsKeyPressed(KEY_SPACE))
	{
		//cut-off should be 150ms
		//stuff gets counted a second before and after a beat hit
		if (toHit[currentToHit] - timer - offset >= 0.1f || toHit[currentToHit] - timer - offset <= -0.1f)
		{
			misses++;
			light5->color = RED;
		}
		else
		{
			light5->color = GREEN;
		}
		text->SetMessage(std::to_string(timer - offset) + ", " + std::to_string(toHit[currentToHit]));

		//hits.push_back(timer - offset);
		currentToHit++;
	}
}

void Level1Scene::SendPulse(int light, Color col)
{
	if (light > 5)
	{
		bg->Change(col);
	}
	if (light >= 4) 
	{
		lights[light]->Change(0.25f);
		return;
	}
	lights[light]->Change();
}

void Level1Scene::Setuppulses()
{
	pulses.clear();
	//setup the pulses for the specific time and the respective light
	pulses.push_back(Vector2(1.5f, 0));
	pulses.push_back(Vector2(1.875f, 1));
	pulses.push_back(Vector2(2.25f, 2));
	pulses.push_back(Vector2(2.625f, 3));
	toHit.push_back(2.625f);

	pulses.push_back(Vector2(3.0f, 0));
	pulses.push_back(Vector2(3.375f, 1));
	pulses.push_back(Vector2(3.75f, 2));
	pulses.push_back(Vector2(4.125f, 3));
	toHit.push_back(4.125f);

	pulses.push_back(Vector2(6.0f, 0));
	pulses.push_back(Vector2(6.75f, 1));
	pulses.push_back(Vector2(7.5f, 2));
	pulses.push_back(Vector2(8.25f, 3));
	toHit.push_back(8.25f);

	pulses.push_back(Vector2(9.0f, 0));
	pulses.push_back(Vector2(9.75f, 1));
	pulses.push_back(Vector2(10.5f, 2));
	pulses.push_back(Vector2(11.25f, 3));
	toHit.push_back(11.25f);

	pulses.push_back(Vector2(12.0f, 0));

	pulses.push_back(Vector2(13.875f, 4));
	pulses.push_back(Vector2(14.25f, 4));
	pulses.push_back(Vector2(14.625f, 4));
	pulses.push_back(Vector2(15.0f, 4));
	toHit.push_back(15.0f);

	pulses.push_back(Vector2(15.0f, 1));

	pulses.push_back(Vector2(18.0f, 2));

	pulses.push_back(Vector2(21.0f, 3));
	toHit.push_back(21.0f);

	pulses.push_back(Vector2(21.375f, 0));
	pulses.push_back(Vector2(22.125f, 1));
	pulses.push_back(Vector2(22.875f, 2));
	pulses.push_back(Vector2(23.625f, 3));
	toHit.push_back(23.625f);

	pulses.push_back(Vector2(24.0f, 0));
	pulses.push_back(Vector2(24.375f, 1));
	pulses.push_back(Vector2(24.75f, 2));
	pulses.push_back(Vector2(25.125f, 3));
	toHit.push_back(25.125f);

	pulses.push_back(Vector2(25.5f, 0));
	pulses.push_back(Vector2(25.875f, 1));
	pulses.push_back(Vector2(26.25f, 2));
	pulses.push_back(Vector2(26.625f, 3));
	toHit.push_back(26.625f);

	pulses.push_back(Vector2(27.0f, 0));
	pulses.push_back(Vector2(27.375f, 1));
	pulses.push_back(Vector2(27.75f, 2));
	pulses.push_back(Vector2(28.125f, 3));
	toHit.push_back(28.125f);

	pulses.push_back(Vector2(28.5f, 0));
	pulses.push_back(Vector2(28.875f, 1));
	pulses.push_back(Vector2(29.25f, 2));
	pulses.push_back(Vector2(29.625f, 3));
	toHit.push_back(29.625f);

	pulses.push_back(Vector2(30.0f, 0));
	pulses.push_back(Vector2(30.375f, 1));
	pulses.push_back(Vector2(30.75f, 2));
	pulses.push_back(Vector2(31.125f, 3));
	toHit.push_back(31.125f);

	pulses.push_back(Vector2(31.5f, 0));
	pulses.push_back(Vector2(31.875f, 1));
	pulses.push_back(Vector2(32.25f, 2));
	pulses.push_back(Vector2(32.625f, 3));
	toHit.push_back(32.625f);

	pulses.push_back(Vector2(34.875f, 0));
	pulses.push_back(Vector2(35.625f, 1));
	pulses.push_back(Vector2(36.375f, 2));
	pulses.push_back(Vector2(37.125f, 3));
	toHit.push_back(37.125f);

	pulses.push_back(Vector2(39.0f, 0));
	pulses.push_back(Vector2(39.375f, 1));
	pulses.push_back(Vector2(39.75f, 2));
	pulses.push_back(Vector2(40.125f, 3));
	toHit.push_back(40.125f);

	pulses.push_back(Vector2(40.875f, 0));
	pulses.push_back(Vector2(41.625f, 1));
	pulses.push_back(Vector2(42.375f, 2));
	pulses.push_back(Vector2(43.125f, 3));
	toHit.push_back(43.125f);

	pulses.push_back(Vector2(46.125f, 0));
	pulses.push_back(Vector2(46.875f, 1));
	pulses.push_back(Vector2(47.625f, 2));
	pulses.push_back(Vector2(48.375f, 3));
	toHit.push_back(48.375f);

	pulses.push_back(Vector2(49.5f, 0));
	pulses.push_back(Vector2(50.25f, 1));
	pulses.push_back(Vector2(51.0f, 2));
	pulses.push_back(Vector2(51.75f, 3));
	toHit.push_back(51.75f);
}
