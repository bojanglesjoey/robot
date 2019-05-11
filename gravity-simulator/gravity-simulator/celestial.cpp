#include "celestial.h"

celestial::Celestial::Celestial(const sf::Vector2f& radius, const unsigned int point_count) : radius_(radius), point_count_(point_count)
{
	update();
}

const sf::Vector2f& celestial::Celestial::getRadius() const
{
	return radius_;
}

void celestial::Celestial::setRadius(const sf::Vector2f& radius)
{
	radius_ = radius;
	update();
}

//overriding inherited function
std::size_t celestial::Celestial::getPointCount() const
{
	return point_count_;
}

//overriding inherited function
sf::Vector2f celestial::Celestial::getPoint(std::size_t index) const
{
	static const float pi = 3.141592654f;

	float angle = index * 2 * pi / getPointCount() - pi / 2;
	float x = std::cos(angle) * radius_.x;
	float y = std::sin(angle) * radius_.y;

	return sf::Vector2f(radius_.x + x, radius_.y + y);
}

celestial::Celestial::~Celestial()
{
}
