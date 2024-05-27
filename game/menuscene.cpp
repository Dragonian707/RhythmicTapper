#include <fstream>
#include <sstream>

#include "menuscene.h"
#include "settings.h"



MenuScene::MenuScene()
{
	activescene = 0;
	startbutton = new Button("Start Game", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2 - 100));
	AddObject(startbutton);
	startbutton->SetMethod(std::bind(&MenuScene::StartGame, this));

	quitbutton = new Button("Exit", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2 + 100));
	AddObject(quitbutton);
	quitbutton->SetMethod(std::bind(&MenuScene::CloseGame, this));

	//optionbutton = new Button("Options", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2));
	//AddObject(optionbutton);
	//optionbutton->SetMethod(std::bind(&MenuScene::OpenOptions, this));

	backtrack = ResourceManager::Instance()->GetMusic("assets/menu_music.ogg");
	PlayMusicStream(backtrack);
}

MenuScene::~MenuScene()
{
	DeleteObject(startbutton);
	DeleteObject(quitbutton);
}

void MenuScene::update(float deltaTime)
{
	UpdateMusicStream(backtrack);
}

void MenuScene::StartGame()
{
	activescene = 2;
}

//void MenuScene::OpenOptions()
//{
//	activescene = 2;
//}