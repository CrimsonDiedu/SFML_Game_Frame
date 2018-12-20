#pragma once
class BaseObject;

class Game
{
	std::vector<BaseObject*> base;
	sf::RenderWindow * window;
	bool running;
	void Start();
	void End();

	void Update();
	void Render();
public:
	Game();
	~Game();

	void Play();
	void Init(sf::RenderWindow * m_window);


	static int  TwoTo1D(int x, int y, int width);

	static sf::Vector2i GetMousePosition(sf::RenderWindow * window);

};

