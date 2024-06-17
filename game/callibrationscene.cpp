#include <fstream>
#include <sstream>

#include "callibrationscene.h"
#include "scenemanager.h"



CalibrationScene::CalibrationScene()
{
	practicetrack = ResourceManager::Instance()->GetMusic("assets/CalibrationTrack.ogg"); //correct snares hit every 2 seconds, first at 1.5 seconds
	PlayMusicStream(practicetrack);
	finalOffset = 60;
	activescene = 1;

	text = new TextSprite();
	AddObject(text);
	text->SetMessage("Press the spacebar whenever the fourth light would turn on in order to calibrate the input delay");
	text->position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2);

	L1 = new IndicatorLight(LIME);
	L1->position = Vector2(SCRWIDTH / 2 - 75, SCRHEIGHT / 4);
	AddObject(L1);
	L2 = new IndicatorLight(GREEN);
	L2->position = Vector2(SCRWIDTH / 2 - 25, SCRHEIGHT / 4);
	AddObject(L2);
	L3 = new IndicatorLight(ORANGE);
	L3->position = Vector2(SCRWIDTH / 2 + 25, SCRHEIGHT / 4);
	AddObject(L3);
	L4 = new IndicatorLight(RED);
	L4->position = Vector2(SCRWIDTH / 2 + 75, SCRHEIGHT / 4);
	AddObject(L4);
}

CalibrationScene::~CalibrationScene()
{
	DeleteObject(L1);
	DeleteObject(L2);
	DeleteObject(L3);
	DeleteObject(L4);
	DeleteObject(text);
}

void CalibrationScene::update(float deltaTime)
{
	UpdateMusicStream(practicetrack);
	if (IsKeyPressed(KEY_BACKSPACE))
	{
		CloseGame();
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		activescene = 2;
	}

	if (calculated) { return; }

	timer += deltaTime;

	if (IsKeyPressed(KEY_SPACE))
	{
		offsets.push_back(timer);
	}

	FlashLights();

	if (offsets.size() >= 10) { CalculateOffset(); }
}

void CalibrationScene::FlashLights()
{
	if (fmod(timer, 2) < 0.2f && !L1Bool)
	{
		L1->Change(0.5f);
		L1Bool = true;
		L2Bool = false;
		L3Bool = false;
		L4Bool = false;
		return;
	}
	if (fmod(timer, 2) > 0.5f && !L2Bool)
	{
		L2->Change(0.5f);
		L2Bool = true;
		return;
	}
	if (fmod(timer, 2) > 1.0f && !L3Bool)
	{
		L3->Change(0.5f);
		L3Bool = true;
		return;
	}
	if (fmod(timer, 2) > 1.5f && !L4Bool)
	{
		L4->Change(0.5f);
		L4Bool = true;
		L1Bool = false;
		return;
	}
}

void CalibrationScene::CalculateOffset()
{
	int i = 0;
	float total = 0;
	for (i; i < offsets.size(); i++)
	{
		offsets[i] = fmod(offsets[i], 2) - 1.5f;
		total += offsets[i];
	}
	finalOffset = total / i;

	std::string t = "   Final offset: ";
	t += std::to_string(finalOffset);
	t += "\n\nPress enter to exit calibration";

	text->SetMessage(t);
	SceneManager::Instance()->SetOffset(finalOffset);
	calculated = true;

	RemoveObject(L1);
	RemoveObject(L2);
	RemoveObject(L3);
	RemoveObject(L4);
}