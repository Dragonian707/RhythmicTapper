#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "raylib.h"

#include "framework/scene.h"
#include "menuscene.h"
#include "level1scene.h"
#include "callibrationscene.h"

class SceneManager
{
public:
	static SceneManager* Instance(); //singleton

	Scene* GetActiveScene();

	void SetActiveScene();

	void SetOffset(float offset) { timingOffset = offset; }

private:
	static SceneManager* _instance;
	/// @brief Constructor
	SceneManager();
	/// @brief Destructor
	virtual ~SceneManager();

	Scene* currentScene = nullptr;

	enum Active {menuscene, calibrationscene, level1, level2};
	Active active;

	float timingOffset = 0;
};

#endif
