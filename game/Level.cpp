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
	AddObject(flavorText);
}

Level::~Level()
{
	
}

void Level::RestartLevel(Music song)
{
	//reset the level
	ready = false;
	misses = 0;
	grade = 'S';
	StopMusicStream(song);
	//PlayMusicStream(song);
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

std::string Level::CalculateGrade()
{
	if (misses >= 16)		{ grade = "F"; }
	else if (misses >= 12)  { grade = "D"; }
	else if (misses >= 8)	{ grade = "C"; }
	else if (misses >= 4)	{ grade = "B"; }
	else if (misses >= 1)	{ grade = "A"; }
	else					{ grade = "S"; }
	
	return grade;
}

void Level::ShowGrade()
{
	
}