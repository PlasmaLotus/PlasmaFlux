#include "PlayerAnimator.h"



PlayerAnimator::PlayerAnimator()
{
	init();
}

PlayerAnimator::PlayerAnimator(Player *p):
	player(p)
{
	init();
}


PlayerAnimator::~PlayerAnimator()
{
}

void PlayerAnimator::setPlayer(Player *p) {
	player = p;
}
bool PlayerAnimator::init()
{
	if (!playerTexture.loadFromFile("assets/images/2664.png"))
	{
		printf("unable ot load player Texture");
		return false;
	}
	playerSprite.setTexture(playerTexture);
	return true;
}

void PlayerAnimator::tick()
{
	if (player != NULL)
	{
		playerpos = player->getPrevPos();
		playerSprite.setTextureRect(sf::IntRect(6 , 9, 20, 18));
		posX = player->getPrevXPos() - 2;
		posY = player->getPrevYPos() - 2;
		playerSprite.setPosition(posX, posY);
	}
}

sf::Sprite PlayerAnimator::getSprite()
{
	return playerSprite;
}

sf::Sprite *PlayerAnimator::getSpriteP()
{
	return &playerSprite;
}

sf::Texture PlayerAnimator::getTexture()
{
	return playerTexture;
}

float PlayerAnimator::getPosX() {
	return posX;
}

float PlayerAnimator::getPosY() {
	return posY;
}

int PlayerAnimator::getTexturePosX()
{
	return 16;
}

int PlayerAnimator::getTexturePosY()
{
	return 16;
}

int PlayerAnimator::getWidth() {
	return width;
}

int PlayerAnimator::getHeight() {
	return height;
}