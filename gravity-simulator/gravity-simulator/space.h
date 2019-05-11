#ifndef SPACE_H
#define SPACE_H

#include "celestial.h"

namespace space
{ 
class Space
{
public:
	Space(sf::RenderWindow& window);

	void addCelestial(const sf::Vector2f& spawn_position, const sf::Vector2f& radius, const unsigned int point_count);

	void spawnCelestials() const;

	void applyGravity(std::vector<celestial::Celestial>& celestials);

	virtual ~Space();

private:
	std::vector<celestial::Celestial> celestials_;
	sf::RenderWindow& window_;
	const float gravity_;
	int population_;
};
}
#endif // SPACE_H