#include <fstream>
#include <sstream>

#include "indicatorlight.h"


//when a beat happens call a method named 'pulse' which takes a float argument with how long the time between flashes should be.
//this should enable me to (hopefuly) send multiple pulses after eachother and in different rhythms
IndicatorLight::IndicatorLight() : DrawSprite("assets/fullLight.png")
{

}

IndicatorLight::~IndicatorLight()
{
	
}

void IndicatorLight::update(float deltaTime)
{

}