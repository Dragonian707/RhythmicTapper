#include <fstream>
#include <sstream>

#include "scene.h"



Scene::Scene()
{
	
}

Scene::~Scene()
{
	for (size_t i = 0; i < sprites.size(); i++)
	{
		delete sprites[i];
		sprites[i] = nullptr;
	}
}

void Scene::UpdateObject(float deltatime)
{
	this->update(deltatime);

	for (Sprite* spr : sprites)
	{
		if (spr == nullptr)
		{
			DeleteObject(spr);
		}
		else 
		{
			spr->UpdateObject(deltatime);
		}
	}
}

void Scene::AddObject(Sprite* sprite)
{
	sprites.push_back(sprite);
}

void Scene::DeleteObject(Sprite* sprite)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i] == sprite)
		{
			sprites.erase(sprites.begin() + i);
			delete sprite;
			sprite = nullptr;
		}
	}
}

void Scene::CloseGame()
{
	state = closegame;
}