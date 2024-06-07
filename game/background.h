#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "framework/drawsprite.h"
#include "settings.h";

class Background : public DrawSprite
{
public:
	/// @brief Constructor
	Background(std::string bgPath);
	/// @brief Destructor
	virtual ~Background();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	//change the background color to the specified color
	void Change(Color col);

private:

};

#endif
