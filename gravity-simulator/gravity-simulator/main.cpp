#include <iostream>

#include <SFML/Graphics.hpp>
#include "space.h"
#include "celestial.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "The Universe");
	sf::Clock clock;

	std::vector<celestial::Celestial> celestials;

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
					celestial::Celestial celestial(sf::Vector2f(5.f, 5.f), 100);
					celestial.setFillColor(sf::Color::Green);
					//currently does not draw to centre/origin of circle
					celestial.setPosition(spawn_x, spawn_y);
					celestials.push_back(celestial);
				}

			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		/*if (elapsed.asSeconds() > 1)
		{
			clock.restart();
		}
		*/

		for (auto c : celestials)
		{
			window.draw(c);
		}

		window.display();
		
	}

	return 0;
}