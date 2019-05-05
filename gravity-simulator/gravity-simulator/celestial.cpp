#include "celestial.h"

celestial::Celestial::Celestial(sf::Vector2f radius, unsigned int point_count) : radius_(radius), point_count_(point_count)
{
	update();
}

std::size_t celestial::Celestial::getPointCount() const
{
	return point_count_;
}

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
