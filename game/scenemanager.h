#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "raylib.h"

#include "framework/scene.h"
#include "menuscene.h"
#include "gamescene.h"

class SceneManager
{
public:
	static SceneManager* Instance(); //singleton

	Scene* GetActiveScene();

	void SetActiveScene();

private:
	static SceneManager* _instance;
	/// @brief Constructor
	SceneManager();
	/// @brief Destructor
	virtual ~SceneManager();

	Scene* currentScene = nullptr;

	enum Active {menuscene, callibrationscene, level1, level2};
	Active active;
};

#endif
