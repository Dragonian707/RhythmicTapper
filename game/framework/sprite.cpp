#include <fstream>
#include <sstream>

#include "sprite.h"



Sprite::Sprite()
{
	position = Vector2(0.0f, 0.0f);
	rotation = 0.0f;
	scale = 1.0;
}

Sprite::~Sprite()
{
	
}