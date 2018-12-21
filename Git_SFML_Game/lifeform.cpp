#include "stdafx.h"
#include "lifeform.h"


lifeform::lifeform()
{
	secondPerRotation = rand() % 5+1;
	secondsSinceTurn = secondPerRotation;

}


lifeform::~lifeform()
{
}

void lifeform::Update()
{
	PhysicsObject::Update();
	if (Game::GetInstance()->GetTimeSeconds()>secondsSinceTurn) {
		SetDirection((rand() % 4) * 90);
		secondsSinceTurn += secondPerRotation;
		if (rand() % 10 == 0) {
			lifeform * l = new lifeform();
			if (Game::GetInstance()->AddObject(l)) {
				l->SetPosition(position);
				l->SetDirection(GetDirection() + 90.f);
				l->SetSpeed(GetSpeed() + 3);
				l->shape->setScale(shape->getScale() * .8f);
			}
			else {
				delete l;
			}
		}
	}
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
