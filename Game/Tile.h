
#ifndef __Tile__
#define __Tile__

//#include <SFML\Graphics.hpp>

class Tile {
public:

	Tile();
	Tile(int tID, double angle = 0.0, bool isItWater = false);
	~Tile();

	//sf::Sprite getTexture();
	//void setTexture(sf::Texture t);
	//void setSprite(sf::Sprite s);
	void setAngle(double a);
	double getAngle();
	bool collidable();
	int getID();
	bool isWater();

	enum TileType{SolidBlock, PassThrough, Air, Slope};
	

private:
	//sf::Sprite sprite;
	double angle;
	int tileID;
	bool water;
};
#endif
