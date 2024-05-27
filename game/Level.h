#ifndef LEVEL_H
#define LEVEL_H

#include "framework/scene.h"
#include "framework/textsprite.h"
#include "settings.h";

class Level : public Scene
{
protected:
	bool ready = false; //is the user ready to begin

	//restart the level from the beginning including readying up again
	void RestartLevel();

	//pause or unpause the game when the appropriate button or key is pressed
	void PauseUnpauseGame();

	//calculate what the grade should be depending on the amount of mistakes
	void CalculateGrade();

	//show the text on screen displaying the grade you got
	void ShowGrade();

	//tracks when the space bar was hit
	std::vector<float> hits;

	//the amount of offset to add to a spcebar hit every 'beat'
	float offset = 60;

	float timer = 0;

public:
	/// @brief Constructor
	Level(float os);
	/// @brief Destructor
	virtual ~Level();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	//virtual void update(float deltaTime);

private:
	Music leveltrack;

	int score = 0; //the amount of missed inputs
	char grade = 'S'; //the grade you get at the end dependent on missed inputs
	//degrades every 5-10 misses -> S > A > B > C > D > F

	TextSprite* gradeText; //displays the grade on screen
	TextSprite* flavorText; //adds some flovor text under the grade


	bool paused = false; //is the game paused right now
};

#endif
