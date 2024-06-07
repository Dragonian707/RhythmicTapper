#include <fstream>
#include <sstream>

#include "background.h"


Background::Background(std::string bgPath) : DrawSprite(bgPath)
{
	color = WHITE;
}

Background::~Background()
{
	
}

void Background::update(float deltaTime)
{
	
}

void Background::Change(Color col)
{
	color = col;
}