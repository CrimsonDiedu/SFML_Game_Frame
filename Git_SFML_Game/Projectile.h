#pragma once
#include "PhysicsObject.h"
class Projectile :
	public PhysicsObject
{
	float time_remaining;
public:
	Projectile();
	~Projectile();

	void Update();
	void Render(sf::RenderWindow * window);
	void SetTimeRemaining(float timeToExpire);
};

