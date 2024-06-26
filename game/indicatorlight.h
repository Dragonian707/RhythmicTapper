#ifndef INDICATORLIGHT_H
#define INDICATORLIGHT_H

#include "framework/drawsprite.h"
#include "settings.h";

class IndicatorLight : public DrawSprite
{
public:
	/// @brief Constructor
	IndicatorLight(Color defColor);
	/// @brief Destructor
	virtual ~IndicatorLight();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void Change(float time = 0.75f);

private:
	Color defaultColor;

	float timer;
	float changeTime;
};

#endif
