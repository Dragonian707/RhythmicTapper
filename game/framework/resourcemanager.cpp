#include <iostream>
#include <fstream>
#include <sstream>

#include "resourcemanager.h"

ResourceManager* ResourceManager::_instance = nullptr;

ResourceManager::ResourceManager()
{
	std::cout << "Created new ResourceManager" << std::endl;
	_font = LoadFontEx("assets/gunplay_rg.ttf", 32, 0, 250);
}

ResourceManager::~ResourceManager()
{
	
}
 
ResourceManager* ResourceManager::Instance()
{
	if (ResourceManager::_instance == nullptr)
	{
		_instance = new ResourceManager();
	}
	return _instance;
}

Texture2D ResourceManager::GetTexture(std::string path)
{
	if (textures.contains(path))
	{
		return textures[path];
	}
	Texture2D texture;
	try
	{
		texture = LoadTexture(path.c_str());
		if (texture.id <= 0)
		{
			throw texture;
		}
	}
	catch (...)
	{
		texture = LoadTexture("assets/placeholder.png");
	}
	textures[path] = texture;
	return texture;
}

Sound ResourceManager::GetSound(std::string path)
{
	if (sounds.contains(path))
	{
		return sounds[path];
	}
	Sound sound;
	sound = LoadSound(path.c_str());
	sounds[path] = sound;
	return sound;
}

Music ResourceManager::GetMusic(std::string path)
{
	if (tracks.contains(path))
	{
		return tracks[path];
	}
	Music music;
	music = LoadMusicStream(path.c_str());
	tracks[path] = music;
	return music;
}

void ResourceManager::Cleanup()
{
	std::map<std::string, Texture2D>::iterator text_it;
	for (text_it = textures.begin(); text_it != textures.end(); ++text_it) {
		std::cout << "unloading " << text_it->first << std::endl;
		UnloadTexture(text_it->second);
	}

	std::map<std::string, Sound>::iterator sound_it;
	for (sound_it = sounds.begin(); sound_it != sounds.end(); ++sound_it) {
		std::cout << "unloading " << sound_it->first << std::endl;
		UnloadSound(sound_it->second);
	}

	std::map<std::string, Music>::iterator music_it;
	for (music_it = tracks.begin(); music_it != tracks.end(); ++music_it) {
		std::cout << "unloading " << music_it->first << std::endl;
		UnloadMusicStream(music_it->second);
	}

	std::cout << "unloading font\n";
	UnloadFont(_font);
}

