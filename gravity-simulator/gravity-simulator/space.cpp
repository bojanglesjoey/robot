#include "space.h"

space::Space::Space(sf::RenderWindow& window) : gravity_(9.8), population_(0), window_(window)
{
}

void space::Space::addCelestial(const sf::Vector2f& spawn_position, const sf::Vector2f& radius, const unsigned int point_count)
{
	celestial::Celestial celestial(radius, point_count);
	celestial.setPosition(spawn_position);
	celestial.setFillColor(sf::Color::Green);
	celestials_.push_back(celestial);
	population_++;
}

void space::Space::spawnCelestials() const
{
	for (auto celestial : celestials_)
	{
		window_.draw(celestial);
	}
}

void space::Space::applyGravity(std::vector<celestial::Celestial>& celestials)
{

}

space::Space::~Space()
{
}
