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
		position.x = size.x;
	}
	else if (position.y < 0) {
		position.y = size.y;
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

	int dir = d / 90;
	TextureManager * tex = Game::GetInstance()->GetTextureManager();
	sf::Texture * texture = nullptr;
	switch (dir) {
	case 0:
		texture = tex->LoadImage("Resources/GenericMinion_0.png");
		break;
	case 1:
		texture = tex->LoadImage("Resources/GenericMinion_1.png");
		break;
	case 2:
		texture = tex->LoadImage("Resources/GenericMinion_2.png");
		break;
	case 3:
		texture = tex->LoadImage("Resources/GenericMinion_3.png");
		break;
	}
	shape->setTexture(texture);
}
