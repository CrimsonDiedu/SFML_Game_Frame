// SFML_Template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	
	Game g;

	g.Init(&window);
	g.Play();
	

		

	return 0;
}