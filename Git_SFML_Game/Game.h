#pragma once
class PhysicsObject;

class Game
{
	std::vector<PhysicsObject*> base;
	sf::RenderWindow * window;
	TextureManager textureManager;
	bool running;
	void Start();
	void End();

	void Update();
	void Render();
	Game();
	static Game * instance;
public:
	~Game();

	void Play();
	void Init(sf::RenderWindow * m_window);


	static int  TwoTo1D(int x, int y, int width);
	static Game * GetInstance();
	static sf::Vector2i GetMousePosition(sf::RenderWindow * window);

	TextureManager * GetTextureManager();
};

