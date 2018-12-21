#pragma once
class Lifeform : public PhysicsObject
{
	float hp;
public:
	Lifeform();
	~Lifeform();

	void Update();
	void Render(sf::RenderWindow * window);
	void Collision(BaseObject * other);
	void SetDirection(float d);
};

