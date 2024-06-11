#ifndef LEVEL1SCENE_H
#define LEVEL1SCENE_H

#include "framework/scene.h"
#include "framework/textsprite.h"
#include "indicatorlight.h"
#include "Level.h"
#include "background.h"

class Level1Scene : public Level
{
public:
	/// @brief Constructor
	Level1Scene(float os, std::string music);
	/// @brief Destructor
	virtual ~Level1Scene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Music leveltrack;

	TextSprite* text;

	IndicatorLight* light1;
	IndicatorLight* light2;
	IndicatorLight* light3;
	IndicatorLight* light4;
	IndicatorLight* light5;

	std::vector<IndicatorLight*> lights;

	//track when the background needs to change to what color
	std::vector<float> bgPulses;
	std::vector<Color> bgColors;

	int currentToHit = 0;

	Background* bg;

	// sends a pulse to the light
	// @param light: the light to send a pulse to
	void SendPulse(int light, Color col = WHITE);

	//sets up all the times specific lights need to flicker to indicate hit beats
	void SetupPulses();

	//gets called every frame
	//checks whether there is a hit incoming and when the spacebar is tapped if it's good enough or not
	void CheckHits();

	//float score = 0;
	//bool paused = false;

	//void ResetScene();
	//void PauseGame();
	//void OpenOptions();
};

#endif
