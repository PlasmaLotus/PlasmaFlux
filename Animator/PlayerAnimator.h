
#ifndef __PlayerAnimator__
#define __PlayerAnimator__

#include <SFML\Graphics.hpp>
#include "../Game/Player.h"

class PlayerAnimator {
public:
	PlayerAnimator();
	PlayerAnimator(Player * p);
	~PlayerAnimator();
	void setPlayer(Player * p);
	bool init();
	void tick();
	sf::Sprite getSprite();
	sf::Sprite * getSpriteP();
	sf::Texture getTexture();

	float getPosX();
	float getPosY();
	int getTexturePosX();
	int getTexturePosY();
	int getWidth();
	int getHeight();


private:
	int time = 0;
	Player *player;
	Vec *playerpos;
	float posX;
	float posY;
	int width = 20;
	int height = 18;
	//base is 20x18
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
};

#endif