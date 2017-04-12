
#ifndef __Tile__
#define __Tile__

//#include <SFML\Graphics.hpp>
enum TileBound { Top, Bottom, East, West };//East = Right
enum TileType { SolidBlock, PassThrough, Air, Slope };
class Tile {
public:

	Tile();
	Tile(int tID, double angle = 0.0, bool isItWater = false);
	Tile(int tID, TileType ty = TileType::SolidBlock, double ang = 0.0, bool isItWater = false);
	~Tile();

	void setAngle(double a);
	double getAngle();
	TileType getType();
	bool collidable();
	bool collidable(TileBound b);
	int getID();
	bool isWater();
	void setPosition(int x, int y);
	int getPosX();
	int getPosY();
	
	

private:
	//sf::Sprite sprite;
	double angle;
	int tileID;
	bool water;
	TileType type;
	int posX;
	int posY;

	/*Represents if there is a collision possible on those bounds*/
	bool boundsUp, boundsDown, boundsLeft, boundsRight;//true means a collision is possible
};
#endif
