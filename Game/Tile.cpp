#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(int tID, double ang, bool isItWater) :
	tileID(tID),
	angle(ang),
	water(isItWater)
{
}



Tile::~Tile()
{
}

bool Tile::isWater()
{
	return water;
}

bool Tile::collidable() {
	return !isWater();
}
