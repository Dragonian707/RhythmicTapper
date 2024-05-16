#include <fstream>
#include <sstream>

#include "drawsprite.h"



DrawSprite::DrawSprite(std::string filePath) : Sprite()
{
	texture = ResourceManager::Instance()->GetTexture(filePath);
	//if (texture.id <= 0)
	//{
	//	texture = ResourceManager::Instance()->GetTexture("assets/placeholder.png");
	//}
	color = WHITE;
}

DrawSprite::~DrawSprite()
{
	
}

void DrawSprite::UpdateObject(float deltatime)
{
	this->Draw();
	this->update(deltatime);
}

void DrawSprite::Draw()
{
	Rectangle sourceRec = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
	Rectangle destRec = { position.x, position.y, (float)texture.width * scale, (float)texture.height * scale };
	Vector2 origin = { texture.width / 2 * scale, texture.height / 2 * scale};

	DrawTexturePro(texture, sourceRec, destRec, origin, rotation, color);
}