#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "raylib.h"
#include <iostream>
#include <map>

class ResourceManager
{
public:

	static ResourceManager* Instance(); //singleton

	/// @brief Get a texture from the specified path
	Texture2D GetTexture(std::string path);

	Sound GetSound(std::string path);
	
	Music GetMusic(std::string path);

	Font GetFont() { return _font; };

	void Cleanup();

private:

	static ResourceManager* _instance;
	/// @brief Constructor
	ResourceManager();
	/// @brief Destructor
	virtual ~ResourceManager();

	std::map<std::string, Texture2D> textures;
	std::map<std::string, Sound> sounds;
	std::map<std::string, Music> tracks;
	Font _font;
};

#endif
