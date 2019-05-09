#ifndef CELESTIAL_H
#define CELESTIAL_H

#include <SFML/Graphics.hpp>

namespace celestial
{
class Celestial : public sf::Shape
{
public:
	Celestial(sf::Vector2f radius, unsigned int point_count);

	std::size_t getPointCount() const;

	sf::Vector2f getPoint(std::size_t index) const;

	virtual ~Celestial();

private:
	sf::Vector2f radius_;
	unsigned int point_count_;
};
}

#endif // CELESTIAL_H

