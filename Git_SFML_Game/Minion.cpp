#include "stdafx.h"

Minion::Minion()
{
	shape->setFillColor(sf::Color::Red);
	timer = new Timer(this, 0.5f, true,0.0251f);
	Game::GetInstance()->AddTimer(timer);
	
}

Minion::~Minion()
{
}

void Minion::Update()
{
	Lifeform::Update();
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
	
	sf::CircleShape * dot;
	if (dotTrail.size() < 50) {
		dot = new sf::CircleShape(2, 10);
	}
	else {
		dot = dotTrail[0];
		dotTrail.erase(dotTrail.begin());
		
	}
	dotTrail.push_back(dot);
	dot->setPosition(GetPosition());
}

void Minion::Notify()
{
	AddDot();
}
