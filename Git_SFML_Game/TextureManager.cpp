#include "stdafx.h"
#include "TextureManager.h"


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
	for (unsigned int i = 0; i < textures.size(); i++) {
		delete textures[i];
	}
	textures.clear();
}

sf::Texture * TextureManager::LoadImage(const char * filename)
{
	sf::Texture * texture = nullptr;
	bool foundTexture = false;
	for (unsigned int i = 0; i < textures.size(); i++) {
		if (strcmp(textures[i]->name, filename) == 0) {
			texture = textures[i]->tex;
			foundTexture = true;
			break;
		}
	}
	if (!foundTexture) {
		TextureData * NewTexture = new TextureData();
		NewTexture->name = filename;
		NewTexture->tex = texture = new sf::Texture();
		if (texture->loadFromFile(filename)) {
			std::cout<<"Loaded "<<filename<<" Successfully";
		}
		else {
			std::cout << "\nYouCouldn'tLoadidiot";
		}
	}
	return texture;
}
