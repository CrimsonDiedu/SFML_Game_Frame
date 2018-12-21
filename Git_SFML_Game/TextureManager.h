#pragma once
class TextureManager
{
	struct TextureData {
		const char * name;
		sf::Texture * tex;
	};
	std::vector<TextureData*> textures;
public:
	TextureManager();
	~TextureManager();

	sf::Texture * LoadImage(const char * filename);
};

