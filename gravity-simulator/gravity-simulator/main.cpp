#include <iostream>

#include <SFML/Graphics.hpp>
#include "celestial.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Window");
	sf::Clock clock;

	celestial::Celestial celestial(sf::Vector2f(25.f, 25.f), 100);
	celestial.setFillColor(sf::Color::Green);
	celestial.setPosition(200.f, 200.f);

	while (window.isOpen())
	{
		sf::Event event;
		sf::Time elapsed = clock.getElapsedTime();
		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (elapsed.asSeconds() > 1)
		{
			sf::Vector2f current_position = celestial.getPosition();
			celestial.move(30.f, 30.f);
			clock.restart();
		}

		window.clear();
		window.draw(celestial);
		window.display();
	}

	return 0;
}