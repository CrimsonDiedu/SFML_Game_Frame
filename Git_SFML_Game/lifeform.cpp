#include "stdafx.h"
#include "lifeform.h"


lifeform::lifeform()
{
}


lifeform::~lifeform()
{
}

void lifeform::Update()
{
	PhysicsObject::Update();
}

void lifeform::Render(sf::RenderWindow * window)
{
	PhysicsObject::Render(window);
}

void lifeform::Collision(BaseObject * other)
{
}

void lifeform::SetDirection(float d)
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
