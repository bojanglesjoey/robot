#include <SFML/Graphics.hpp>
#include "celestial.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Window");
	
	celestial::Celestial celestial(sf::Vector2f(10.f, 10.f), 30);
	celestial.setFillColor(sf::Color::Green);
	celestial.setOutlineThickness(10.f);
	celestial.setOutlineColor(sf::Color(250, 150, 100));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(celestial);
		window.display();
	}

	return 0;
}