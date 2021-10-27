#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <unordered_map>
#include <SDL.h>

class TextureManager
{
public:
	static TextureManager* getInstance()
	{
		static TextureManager instance;
		return &instance;
	}

	TextureManager(TextureManager const&) = delete;
	void operator=(TextureManager const&) = delete;

	void add(std::string ID, SDL_Texture* texture) { m_textureMap.emplace(ID, texture); }
	SDL_Texture* get(std::string ID) { return m_textureMap.at(ID); }

private:
	TextureManager() {}
	std::unordered_map<std::string, SDL_Texture*> m_textureMap;
};

#endif