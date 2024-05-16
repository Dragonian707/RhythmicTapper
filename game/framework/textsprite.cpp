#include <fstream>
#include <sstream>

#include "textsprite.h"



TextSprite::TextSprite()
{
	position = Vector2(0.0f, 0.0f);
	rotation = 0.0f;
	scale = 1.0;
	message = "NO MESSAGE";
	color = WHITE;
}

TextSprite::~TextSprite()
{
	
}

void TextSprite::UpdateObject(float deltatime)
{
	update(deltatime);
	Draw();
}

void TextSprite::update(float deltatime)
{
	;
}

void TextSprite::Draw()
{
	if (centerText)
	{
		//-------------set position from the middle of text-----------------------------
		const Vector2 text_size = MeasureTextEx(font, message.c_str(), 30 * scale, 1);
		Vector2 pos = Vector2Subtract(position, Vector2Divide(text_size, 2));
		DrawTextEx(font, message.c_str(), pos, 30 * scale, 1, color);
		//------------------------------------------------------------------------------
	}
	else
	{
		//-------------set position from top left of text-------------------------------
		DrawTextEx(font, message.c_str(), position, 30 * scale, 1, color);
		//------------------------------------------------------------------------------
	}
}