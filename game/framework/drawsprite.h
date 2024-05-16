#ifndef DRAWSPRITE_H
#define DRAWSPRITE_H

#include "raylib.h"
#include "resourcemanager.h"
#include "sprite.h"
#include <vector>

class DrawSprite : public Sprite
{
protected:
	Texture2D texture;

public:
	/// @brief Constructor
	DrawSprite(std::string filePath);
	/// @brief Destructor
	virtual ~DrawSprite();

	Color color;

	virtual void UpdateObject(float deltatime);

	Texture2D getTexture() { return texture; };

private:
	void Draw();
};

#endif
