#ifndef LEVEL_H
#define LEVEL_H

#include "framework/scene.h"
#include "framework/textsprite.h"

//class Spawner;

class Level
{
public:
	/// @brief Constructor
	Level();
	/// @brief Destructor
	virtual ~Level();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Music leveltrack;

	//float score = 0;
	bool paused = false;
	bool ready = false;

	void RestartLevel();
	void PauseUnpauseGame();
	//void OpenOptions();
};

#endif
