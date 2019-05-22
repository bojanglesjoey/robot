#include <iostream>

#include "space.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "The Universe");
	sf::Clock clock;
	space::Space space(window);
	
	//celestial default test values
	sf::Vector2f spawn_position;
	sf::Vector2f radius(5.f, 5.f);
	const unsigned int point_count = 100;

	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			
			spawn_position.x = sf::Mouse::Mouse::getPosition(window).x;
			spawn_position.y = sf::Mouse::Mouse::getPosition(window).y;
			
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

		sf::Time elapsed = clock.getElapsedTime();
		std::cout << elapsed.asSeconds() << std::endl;

		/*if (elapsed.asSeconds() > 1)
		{
			clock.restart();
		}
		*/

		window.clear();

		space.spawnCelestials();

		

		window.display();
		
	}

	return 0;
}