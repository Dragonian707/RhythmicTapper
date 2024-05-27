#include <fstream>
#include <sstream>

#include "level1scene.h"



Level1Scene::Level1Scene(float os, std::string music) : Level(os)
{
	leveltrack = ResourceManager::Instance()->GetMusic(music);
	PlayMusicStream(leveltrack);
	activescene = 2;
	offset = os;

	text = new TextSprite();
	text->position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2);
	text->SetMessage("");
	text->scale = 0.5f;
}

Level1Scene::~Level1Scene()
{
	
}

void Level1Scene::update(float deltaTime)
{
	text->UpdateObject(deltaTime);
	if (IsKeyPressed(KEY_BACKSPACE)) //Can't use escape sadly, too much input delay
	{
		CloseGame();
	}
	if (!ready)
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			ready = true;
		}
		return;
	}
	timer += deltaTime;
	UpdateMusicStream(leveltrack);
	if (IsKeyPressed(KEY_R))
	{
		PauseMusicStream(leveltrack);
		RestartLevel();
		timer = 0;
	}

	if (IsKeyPressed(KEY_SPACE))
	{
		hits.push_back(timer - offset);
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		//show all times space was hit
		std::string t;
		for (int i = 0; i < hits.size(); i++)
		{
			t += std::to_string(hits[i]);
			t += "\n";
		}
		text->SetMessage(t);
	}
}

