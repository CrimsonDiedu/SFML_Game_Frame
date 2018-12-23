#pragma once
class Timer;

class Minion :
	public Lifeform,
	public Observer
{
	Timer * timer;
	std::vector<sf::CircleShape *> dotTrail;
public:
	Minion();
	~Minion();

	void Update();
	void Render(sf::RenderWindow * window);
	void SetDirection(float d);
	void AddDot();
	void Notify();
};

