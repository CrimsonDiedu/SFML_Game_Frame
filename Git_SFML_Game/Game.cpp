#include "stdafx.h"

Game * instance = 0;

void Game::Start()
{
	//initialize things here
	running = true;

	PhysicsObject * p = new PhysicsObject();
	p->SetSpeed(5);
	p->SetDirection(0);
	base.push_back(p);
	p = new PhysicsObject();
	p->SetPosition(sf::Vector2f(200, 0));
	p->GetShape()->setFillColor(sf::Color::Blue);
	p->SetSpeed(-5);
	p->SetDirection(0);
	base.push_back(p);
}

void Game::End()
{
	//destroy everything initialized in start

	window->close();
	running = false;
}

void Game::Update()
{
	//Update all game objects, typically passing the change in time between updates
	for (unsigned int i = 0; i < base.size(); i++) {
		for (unsigned int j = 0; j < base.size(); j++) {
			if (i != j) {
				if (base[i]->GetShape()->getGlobalBounds()
					.intersects(base[j]->GetShape()->getGlobalBounds())) {
					base[i]->Collision(base[j]);
				}
				//PROJECTILE Collision check Logic 
				//parameters: * to other object
				//if other can take damage and 
				//other.teamid != teamid then damage other x amount
			}
		}
	}
	for (unsigned int i = 0; i < base.size(); i++) {
		base[i]->Update();
	}
	
}

void Game::Render()
{
	window->clear();
	//window.draw(shape);
	//loop through all vectors and lists of objects, and run their update method
	//typically, passing in a renderwindow to the object's rendering method
	for (unsigned int i = 0; i < base.size(); i++) {
		base[i]->Render(window);
	}
	window->display();
}

Game::Game()
{
}


Game::~Game()
{
}

void Game::Play()
{
	Start();
	while (running) {
		while (window->isOpen()) {
			sf::Event mevent;
			while (window->pollEvent(mevent))
			{
				if (mevent.type == sf::Event::Closed) {
					End();
				}
			}
			Update();
			Render();
		}
	}
}

void Game::Init(sf::RenderWindow * m_window)
{
	window = m_window;
}

int Game::TwoTo1D(int x, int y, int width)
{
	return x * width + y;
}

Game * Game::GetInstance()
{
	if (instance == 0) {
		instance = new Game();
	}

	return instance;
}

sf::Vector2i Game::GetMousePosition(sf::RenderWindow * window)
{
	sf::Vector2i offset(12, 54);
	return sf::Mouse::getPosition() - window->getPosition() - offset;
}
