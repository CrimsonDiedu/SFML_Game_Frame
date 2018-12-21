// SFML_Template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
	
	Game * g = Game::GetInstance();

	g->Init(&window);
	g->Play();
	

		
	

	return 0;
}