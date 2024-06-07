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
	text->SetMessage("Calibration Scene");
	text->position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2);
}

CalibrationScene::~CalibrationScene()
{
	
}

void CalibrationScene::update(float deltaTime)
{
	text->UpdateObject(deltaTime);
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

	if (offsets.size() >= 10) { CalculateOffset(); }
}

void CalibrationScene::CalculateOffset()
{
	offsets[0] = fmod(offsets[0], 2) - 1.5f;
	offsets[1] = fmod(offsets[1], 2) - 1.5f;
	offsets[2] = fmod(offsets[2], 2) - 1.5f;
	offsets[3] = fmod(offsets[3], 2) - 1.5f;
	offsets[4] = fmod(offsets[4], 2) - 1.5f;
	offsets[5] = fmod(offsets[5], 2) - 1.5f;
	offsets[6] = fmod(offsets[6], 2) - 1.5f;
	offsets[7] = fmod(offsets[7], 2) - 1.5f;
	offsets[8] = fmod(offsets[8], 2) - 1.5f;
	offsets[9] = fmod(offsets[9], 2) - 1.5f;

	int i = 0;
	float total = 0;
	for (i; i < offsets.size(); i++)
	{
		total += offsets[i];
	}
	finalOffset = total / i;

	std::string t = "";
	t += std::to_string(offsets[0]);
	t += "\n";
	t += std::to_string(offsets[1]);
	t += "\n";
	t += std::to_string(offsets[2]);
	t += "\n";
	t += std::to_string(offsets[3]);
	t += "\n";
	t += std::to_string(offsets[4]);
	t += "\n";
	t += std::to_string(offsets[5]);
	t += "\n";
	t += std::to_string(offsets[6]);
	t += "\n";
	t += std::to_string(offsets[7]);
	t += "\n";
	t += std::to_string(offsets[8]);
	t += "\n";
	t += std::to_string(offsets[9]);
	t += "\n\n";
	t += std::to_string(finalOffset);

	text->SetMessage(t);
	SceneManager::Instance()->SetOffset(finalOffset);
	calculated = true;
}