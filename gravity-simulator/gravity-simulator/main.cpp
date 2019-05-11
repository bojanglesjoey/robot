#include <iostream>

#include <SFML/Graphics.hpp>
#include "space.h"
#include "celestial.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "The Universe");
	//sf::Clock clock;
	space::Space space(window);
	
	while (window.isOpen())
	{
		sf::Event event;
		//sf::Time elapsed = clock.getElapsedTime();

		while (window.pollEvent(event))
		{
			sf::Vector2f spawn_position;
			spawn_position.x = sf::Mouse::Mouse::getPosition(window).x;
			spawn_position.y = sf::Mouse::Mouse::getPosition(window).y;
			sf::Vector2f radius(5.f, 5.f);
			const unsigned int point_count = 100;

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
					//currently does not draw to centre/origin of circle
					space.addCelestial(spawn_position, radius, point_count);
					
				}

			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		space.spawnCelestials();

		/*if (elapsed.asSeconds() > 1)
		{
			clock.restart();
		}
		*/

		window.display();
		
	}

	return 0;
}