/*
 * Main.cpp
 *
 *  Created on: 27/06/2020
 *      Author: vinicius
 */

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ParticleSystem.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Particle System!");
	window.setVerticalSyncEnabled(true);
	sf::Clock clock;

	SpawnAreaSpecs saSpecs = {sf::Vector2f(0.0f, 400.0f), sf::Vector2f(50, 50)};
	ParticleSystemSpecs psSpecs = {60, 500, sf::Vector2f(10, 10), sf::Color(0.0f, 100.0f, 200.0f, 255.0f), 2.2f, sf::Vector2f(0.0f, 80.0f), sf::Vector2f(300.0f * 2, -500.0f * 2), 1};
	ParticleSystem ps(saSpecs, psSpecs);

	while (window.isOpen())
	{
		sf::Time eclipsedTime = clock.getElapsedTime();
		clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			ps.setPosition(mousePos);

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		ps.draw(window, sf::RenderStates::Default);
		ps.updatePhysics(eclipsedTime.asSeconds());

		window.display();
	}
}
