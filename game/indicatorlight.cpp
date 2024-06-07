#include <fstream>
#include <sstream>

#include "indicatorlight.h"


//when a beat happens call a method named 'pulse' which takes a float argument with how long the time between flashes should be.
//this should enable me to (hopefuly) send multiple pulses after eachother and in different rhythms
IndicatorLight::IndicatorLight(Color defColor) : DrawSprite("assets/fullLight.png")
{
	scale = 1.25f;
	defaultColor = defColor;
	timer = 0;
	changeTime = 0.75f;
}

IndicatorLight::~IndicatorLight()
{
	
}

void IndicatorLight::update(float deltaTime)
{
	if (color.r != defaultColor.r || color.g != defaultColor.g || color.b != defaultColor.b)
	{
		timer += deltaTime;
	}
	else { return; }

	if (timer >= changeTime)
	{
		color = defaultColor;
		timer = 0;
	}
}
void IndicatorLight::Change(float time)
{
	changeTime = time;
	timer = 0;
	color = WHITE;
}