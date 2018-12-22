#include "stdafx.h"
#include "Game.h"

Game * Game::instance = 0;

#ifdef DEBUG_BUILD
#define BASEOBJECT_LIMIT 25
#else
#define BASEOBJECT_LIMIT 200
#endif

void Game::Start()
{
	//initialize things here
	running = true;
	sf::Vector2u bounds = window->getSize();
	sf::Vector2f pos = sf::Vector2f(bounds.x / 2.f, bounds.y / 2.f);
	Lifeform* lifeform;
	int limit = 18;
	for (int i = 0; i < limit; i++) {
		lifeform = new Minion();
		lifeform->SetPosition(pos);
		lifeform->SetDirection((i % 4) * 90.f);
		lifeform->SetSpeed(5);
		base.push_back(lifeform);
	}
	lastFrameElapsedTime = 0;
}

void Game::End()
{
	//destroy everything initialized in start

	window->close();
	running = false;
}

void Game::Update()
{
	deltaTime = (clock.getElapsedTime().asSeconds()-lastFrameElapsedTime);
	lastFrameElapsedTime += deltaTime;
	
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
	//add any objects created this loop to base vector

	if (queue.size() != 0)
	{
		for (unsigned int i = 0; i < queue.size(); i++) {
			base.push_back(queue[i]);
		}
		queue.clear();
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

TextureManager * Game::GetTextureManager()
{
	return &textureManager;
}

float Game::GetTimeSeconds()
{
	return clock.getElapsedTime().asSeconds();
}

float Game::GetDeltaTime()
{
	return deltaTime;
}

sf::RenderWindow * Game::GetWindow()
{
	return window;
}

bool Game::AddObject(PhysicsObject * object)
{
	bool addedObject = false;
	if (base.size() < BASEOBJECT_LIMIT) {
		queue.push_back(object);
		addedObject = true;
	}
	return addedObject;
	
}
