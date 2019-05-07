#include <iostream>

#include <SFML/Graphics.hpp>
#include "space.h"
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
			float spawn_x = sf::Mouse::Mouse::getPosition(window).x;
			float spawn_y = sf::Mouse::Mouse::getPosition(window).y;

			switch (event.type)
			{
			default:
				break;

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//spawn celestial at spawn_x, spawn_y
				}

			}
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