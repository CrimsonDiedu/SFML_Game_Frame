#include "stdafx.h"

void Game::Start()
{
	//initialize things here
	running = true;
}

void Game::End()
{
	//destroy everything initialized in start
}

void Game::Update()
{
	//Update all game objects, typically passing the change in time between updates
}

void Game::Render()
{
	window->clear();
	//window.draw(shape);
	//loop through all vectors and lists of objects, and run their update method
	//typically, passing in a renderwindow to the object's rendering method
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
		while(window->isOpen)
		sf::Event mevent;
		while (window->pollEvent(mevent))
		{
			if (mevent.type == sf::Event::Closed)
				window->close();
		}
		Update();
		Render();
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

sf::Vector2i Game::GetMousePosition(sf::RenderWindow * window)
{
	sf::Vector2i offset(12, 54);
	return sf::Mouse::getPosition() - window->getPosition() - offset;
}
