#ifndef BUTTON_H
#define BUTTON_H

#include "drawsprite.h"
#include "textsprite.h"
#include <functional>

class Button : public DrawSprite
{
public:
	/// @brief Constructor
	Button(std::string bt, Vector2 pos);
	/// @brief Destructor
	virtual ~Button();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void SetMethod(std::function<void()> method);

private:
	TextSprite* buttontext;
	std::function<void()> methodToDo;
};

#endif
