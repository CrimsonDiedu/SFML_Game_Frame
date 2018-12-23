#include "stdafx.h"

Minion::Minion()
{
	shape->setFillColor(sf::Color::Red);
	timer = new Timer(this, 1, true);
	Game::GetInstance()->AddTimer(timer);
	
}

Minion::~Minion()
{
}

void Minion::Update()
{
	PhysicsObject::Update();
}

void Minion::Render(sf::RenderWindow * window)
{

	for (unsigned int i = 0; i < dotTrail.size(); i++) {
		window->draw(*dotTrail[i]);
	}
	window->draw(*shape);
}

void Minion::SetDirection(float d)
{
	Lifeform::SetDirection(d);

	int dir = (int)d / 90;
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

void Minion::AddDot()
{
	sf::CircleShape * dot = new sf::CircleShape(2, 10);
	dot->setPosition(GetPosition());
	dotTrail.push_back(dot);
}

void Minion::Notify()
{
	AddDot();
}
