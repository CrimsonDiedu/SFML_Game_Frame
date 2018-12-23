#include "stdafx.h"
#include "Projectile.h"


Projectile::Projectile()
{
	
}


Projectile::~Projectile()
{
}

void Projectile::Update()
{
	PhysicsObject::Update();
	//if the timer reaches zero, destroy
	//else subtract dt from timer
}

void Projectile::Render(sf::RenderWindow * window)
{
	PhysicsObject::Render(window);
}

void Projectile::SetTimeRemaining(float timeToExpire)
{
	time_remaining = timeToExpire;
}
