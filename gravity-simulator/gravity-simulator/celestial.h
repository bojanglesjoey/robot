#ifndef CELESTIAL_H
#define CELESTIAL_H

#include <SFML/Graphics.hpp>

namespace celestial
{
class Celestial : public sf::Shape
{
public:
	explicit Celestial(const sf::Vector2f& radius, const unsigned int point_count);

	const sf::Vector2f& getRadius() const;

	void setRadius(const sf::Vector2f& radius);

	virtual std::size_t getPointCount() const;

	virtual sf::Vector2f getPoint(std::size_t index) const;

	virtual ~Celestial();

private:
	sf::Vector2f radius_;
	const unsigned int point_count_;
};
}

#endif // CELESTIAL_H

