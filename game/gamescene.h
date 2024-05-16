#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "framework/scene.h"
#include "framework/textsprite.h"

//class Spawner;

class GameScene : public Scene
{
public:
	/// @brief Constructor
	GameScene();
	/// @brief Destructor
	virtual ~GameScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Music gametrack;

	//float score = 0;
	//bool paused = false;

	//void ResetScene();
	//void PauseGame();
	//void OpenOptions();
};

#endif
