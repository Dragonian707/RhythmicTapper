#ifndef TEXTSPRITE_H
#define TEXTSPRITE_H

#include "raylib.h"
#include "sprite.h"

class TextSprite : public Sprite
{
public:
	/// @brief Constructor
	TextSprite();
	/// @brief Destructor
	virtual ~TextSprite();


	virtual void UpdateObject(float deltatime);
	virtual void update(float deltatime);

	void SetMessage(std::string ms) { message = ms; };
	void CenterText(bool centered) { centerText = centered; };

	Color color;
private:
	void Draw();

	std::string message;
	bool centerText = true;

	Font font = ResourceManager::Instance()->GetFont();
};

#endif
