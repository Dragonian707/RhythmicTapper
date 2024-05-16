#ifndef SPRITE_H
#define SPRITE_H

#include "raylib.h"
#include "raymath.h"
#include "resourcemanager.h"
#include <vector>

class Sprite
{
public:
	friend class Scene;

	/// @brief Constructor
	Sprite();
	/// @brief Destructor
	virtual ~Sprite();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime) = 0;


	//position rotation and scale
	Vector2 position;
	float rotation;
	float scale;

private:

protected:
	virtual void UpdateObject(float deltatime) = 0;

};

#endif
