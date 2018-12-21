#pragma once
class lifeform : public PhysicsObject
{
	float hp;
public:
	lifeform();
	~lifeform();

	void Update();
	void Render(sf::RenderWindow * window);
	void Collision(BaseObject * other);
	void SetDirection(float d);
};

