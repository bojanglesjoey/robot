#ifndef SPACE_H
#define SPACE_H

#include <SFML/Graphics.hpp>
#include "celestial.h"

namespace space
{ 
class Space
{
public:
	Space();
	void spawnCelestial();
	virtual ~Space();
};
}
#endif // SPACE_H