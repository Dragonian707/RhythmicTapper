#ifndef LEVEL1SCENE_H
#define LEVEL1SCENE_H

#include "framework/scene.h"
#include "framework/textsprite.h"

//class Spawner;

class Level1Scene : public Level
{
public:
	/// @brief Constructor
	Level1Scene();
	/// @brief Destructor
	virtual ~Level1Scene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Music leveltrack;

	//float score = 0;
	//bool paused = false;

	//void ResetScene();
	//void PauseGame();
	//void OpenOptions();
};

#endif
