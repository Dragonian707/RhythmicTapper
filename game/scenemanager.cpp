#include <fstream>
#include <sstream>

#include "scenemanager.h"


SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager()
{
	SetActiveScene();
}

SceneManager::~SceneManager()
{
	if (currentScene != nullptr)
	{
		delete currentScene;
		currentScene = nullptr;
	}
}

SceneManager* SceneManager::Instance()
{
	if (SceneManager::_instance == nullptr)
	{
		_instance = new SceneManager();
	}
	return _instance;
}

Scene* SceneManager::GetActiveScene()
{
	SetActiveScene();
	return currentScene;
}

void SceneManager::SetActiveScene()
{
	if (currentScene == nullptr)
	{
		currentScene = new MenuScene();
	}

	if (currentScene->activescene == active)
	{
		return;
	}

	std::cout << "changing scene to " << currentScene->activescene << std::endl;
	switch (currentScene->activescene)
	{
		case 0: //menu scene
			delete currentScene;
			currentScene = new MenuScene();
			active = menuscene;
			break;
		case 1: //callibration scene
			delete currentScene;
			currentScene = new CalibrationScene();
			active = calibrationscene;
			break;
		case 2: //level 1
			delete currentScene;
			currentScene = new Level1Scene(timingOffset, "assets/track1.mp3");
			active = level1;
			break;
		default:
			active = menuscene;
			delete currentScene;
			currentScene = new MenuScene();
			break;
	}
}
