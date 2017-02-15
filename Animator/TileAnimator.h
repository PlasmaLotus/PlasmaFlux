
#include "Y:\PlasmaFlux\src\Animator\Animator.h"

#include "SFML\Graphics.hpp"

class TileAnimator :
	public Animator
{
public:
	TileAnimator();
	TileAnimator(int x, int y, int i, int j);
	virtual ~TileAnimator();
	void tick();
	sf::Texture getTexture();
	void setTexture(sf::Texture t);
	sf::Sprite getSprite();
private:
	sf::Sprite sprite;
	sf::Texture texture;

	int texturePosX;
	int texturePosY;
	int spriteSizeX;
	int spriteSizeY;

};

