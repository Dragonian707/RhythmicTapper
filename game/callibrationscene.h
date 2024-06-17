#ifndef CALIBRATIONSCENE_H
#define CALIBRATIONSCENE_H

#include "framework/scene.h"
#include "framework/textsprite.h"
#include "settings.h"
#include "indicatorlight.h"

//class Spawner;

class CalibrationScene : public Scene
{
public:
	/// @brief Constructor
	CalibrationScene();
	/// @brief Destructor
	virtual ~CalibrationScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	//gets what the offset should be
	float GetOffset() { return finalOffset; }

private:
	Music practicetrack;
	std::vector<float> offsets;
	float finalOffset;
	TextSprite* text;
	float timer = 0;

	void CalculateOffset();

	void FlashLights();

	bool calculated = false;

	IndicatorLight* L1;
	IndicatorLight* L2;
	IndicatorLight* L3;
	IndicatorLight* L4;

	bool L1Bool = false;
	bool L2Bool = false;
	bool L3Bool = false;
	bool L4Bool = false;
};

#endif
