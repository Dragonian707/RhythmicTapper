#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "framework/scene.h"
#include "framework/button.h"

class MenuScene : public Scene
{
public:
	/// @brief Constructor
	MenuScene();
	/// @brief Destructor
	virtual ~MenuScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Button* startbutton;
	Button* quitbutton;
	//Button* optionbutton;

	Music backtrack;

	void StartGame();
	//void OpenOptions();
};

#endif
