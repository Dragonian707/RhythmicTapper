#ifndef LEVEL_H
#define LEVEL_H

#include "framework/scene.h"
#include "framework/textsprite.h"
#include "framework/drawsprite.h"
#include "settings.h";

class Level : public Scene
{
protected:
	bool ready = false; //is the user ready to begin

	//restart the level from the beginning including readying up again
	void RestartLevel(Music song);

	//pause or unpause the game when the appropriate button or key is pressed
	void PauseUnpauseGame();

	//calculate what the grade should be depending on the amount of mistakes
	std::string CalculateGrade();

	//show the text on screen displaying the grade you got
	void ShowGrade();

	//tracks how many misses there were
	int misses = 0;

	//tracks all times the spacebar should be hit
	std::vector<float> toHit;

	//tracks at what time pulses should be given to the player to hit the spacebar on
	std::vector<Vector2> pulses;

	// sends a pulse to the light
	// @param light: the light to send a pulse to
	//virtual void SendPulse(int light, Color col) = 0;

	//the amount of offset to add to a spcebar hit every 'beat'
	float offset = 60;

	std::vector<DrawSprite*> objects;

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

	std::string grade = "S"; //the grade you get at the end dependent on missed inputs
	//degrades every 5-10 misses -> S > A > B > C > D > F

	TextSprite* gradeText; //displays the grade on screen
	TextSprite* flavorText; //adds some flovor text under the grade


	bool paused = false; //is the game paused right now
};

#endif
