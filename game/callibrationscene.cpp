#include <fstream>
#include <sstream>

#include "gamescene.h"



GameScene::GameScene()
{
	gametrack = ResourceManager::Instance()->GetMusic("assets/music_evade.ogg");
	PlayMusicStream(gametrack);
	activescene = 1;
}

GameScene::~GameScene()
{
	
}

void GameScene::update(float deltaTime)
{
	UpdateMusicStream(gametrack);
	if (IsKeyPressed(KEY_BACKSPACE)) //Can't use escape sadly, too much input delay
	{
		CloseGame();
	}
}