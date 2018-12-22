#include "stdafx.h"
#include "Lifeform.h"


Lifeform::Lifeform()
{
}


Lifeform::~Lifeform()
{
}

void Lifeform::Update()
{
	PhysicsObject::Update();
sf::Vector2u size = Game::GetInstance()->GetWindow()->getSize();
	if (position.x < 0) {
		position.x = (float)size.x;
	}
	else if (position.y < 0) {
		position.y = (float)size.y;
	}
	else if (position.x > size.x) {
		position.x = 0;
	}
	else if (position.y > size.y) {
		position.y = 0;
	}
}

void Lifeform::Render(sf::RenderWindow * window)
{
	PhysicsObject::Render(window);
}

void Lifeform::Collision(BaseObject * other)
{
}

void Lifeform::SetDirection(float d)
{
	PhysicsObject::SetDirection(d);

	
}
