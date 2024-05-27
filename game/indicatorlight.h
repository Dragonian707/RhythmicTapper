#ifndef INDICATORLIGHT_H
#define INDICATORLIGHT_H

#include "framework/drawsprite.h"
#include "settings.h";

class IndicatorLight : public DrawSprite
{
public:
	/// @brief Constructor
	IndicatorLight();
	/// @brief Destructor
	virtual ~IndicatorLight();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:

};

#endif
