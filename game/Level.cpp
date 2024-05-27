#include <fstream>
#include <sstream>

#include "Level.h"


//when a beat happens call a method named 'pulse' which takes a float argument with how long the time between flashes should be.
//this should enable me to (hopefuly) send multiple pulses after eachother and in different rhythms
Level::Level(float os)
{
	offset = os;

	gradeText = new TextSprite();
	gradeText->position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2);

	flavorText = new TextSprite();
	flavorText->SetMessage("Doing pretty well eh?");
	flavorText->position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2 - 200);
}

Level::~Level()
{
	
}

void Level::RestartLevel()
{
	//reset the level
	ready = false;
	score = 0;
	grade = 'S';
	StopMusicStream(leveltrack);
	PlayMusicStream(leveltrack);
}

void Level::PauseUnpauseGame()
{
	if (paused)
	{
		//pause game
	}
	else
	{
		//unpause game
	}
	paused = !paused;
}

void Level::CalculateGrade()
{
	if (score >= 25)	{ grade = 'F'; return; }
	if (score >= 17)	{ grade = 'D'; return; }
	if (score >= 12)	{ grade = 'C'; return; }
	if (score >= 5)		{ grade = 'B'; return; }
	if (score >= 1)		{ grade = 'A'; return; }
	
	grade = 'S';
}

void Level::ShowGrade()
{

}