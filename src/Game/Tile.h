
#ifndef __Tile__
#define __Tile__

#include <SFML\Graphics.hpp>

class Tile {
public:

	Tile();
	~Tile();

	sf::Sprite getTexture();
	void setTexture(sf::Texture t);
	void setSprite(sf::Sprite s);
	void setAngle(double a);
	double getAngle();
	bool collidable();

	enum TileType{SolidBlock, PassThrough, Air, Slope};
	

private:
	sf::Sprite sprite;
	double angle;
};
#endif
