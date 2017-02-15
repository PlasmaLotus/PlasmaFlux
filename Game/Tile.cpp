#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(int tID, double ang, bool isItWater) :
	tileID(tID),
	angle(ang),
	water(isItWater)
{
	type = TileType::SolidBlock;
}

Tile::Tile(int tID, TileType ty, double ang, bool isItWater) :
	tileID(tID),
	angle(ang),
	water(isItWater),
	boundsUp(true), 
	boundsDown(true),
	boundsLeft(true), 
	boundsRight(true)
{

	switch (ty) {
	case TileType::PassThrough:
	{
		boundsDown = false;
		boundsLeft = false;
		boundsRight = false;
		break;
	}
	case TileType::Slope:
	{
		break;
	}
	case TileType::SolidBlock:
	default:
	{
		break;
	}
	}

}



Tile::~Tile()
{
}

bool Tile::isWater()
{
	return water;
}

void Tile::setAngle(double a)
{
	angle = a;
}

double Tile::getAngle()
{
	return angle;
}

TileType Tile::getType()
{
	return type;
}

bool Tile::collidable() {
	return true;
}

bool Tile::collidable(TileBound b)
{
	switch(b) 
	{
	case TileBound::Bottom:
	{
		return boundsDown;
		break;
	}
	case TileBound::West:
	{
		return boundsLeft;
		break;
	}
	case TileBound::Top:
	{
		return boundsUp;
		break;
	}
	case TileBound::East:
	{
		return boundsRight;
		break;
	}
	default:
		return true;
	}

	return true;
}

int Tile::getID() {
	return tileID;
}
