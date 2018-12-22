#pragma once
class PhysicsObject;

class Game
{
	std::vector<PhysicsObject*> base,queue;
	sf::RenderWindow * window;
	sf::Clock clock;
	TextureManager textureManager;

	bool running;
	void Start();
	void End();

	void Update();
	void Render();
	Game();
	static Game * instance;
	float deltaTime,lastFrameElapsedTime;
public:
	~Game();

	void Play();
	void Init(sf::RenderWindow * m_window);


	static int  TwoTo1D(int x, int y, int width);
	static Game * GetInstance();
	static sf::Vector2i GetMousePosition(sf::RenderWindow * window);

	TextureManager * GetTextureManager();
	float GetTimeSeconds();
	float GetDeltaTime();
	sf::RenderWindow* GetWindow();
	bool AddObject(PhysicsObject* object);
};

