#ifndef CALIBRATIONSCENE_H
#define CALIBRATIONSCENE_H

#include "framework/scene.h"
#include "framework/textsprite.h"
#include "settings.h"

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

private:
	Music practicetrack;
	std::vector<float> offsets;
	float finalOffset;
	TextSprite* text;
	float timer = 0;

	void CalculateOffset();

	bool calculated = false;
};

#endif
