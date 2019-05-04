#include "celestial.h"

celestial::Celestial::Celestial(sf::Vector2f radius, unsigned int point_count) : radius_(radius), point_count_(point_count)
{
}

std::size_t celestial::Celestial::getPointCount() const
{
	return point_count_;
}

sf::Vector2f celestial::Celestial::getPoint(std::size_t index) const
{
	return sf::Vector2f(radius_.x, radius_.y);
}

celestial::Celestial::~Celestial()
{
}
