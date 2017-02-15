#include "TileAnimator.h"



TileAnimator::TileAnimator()
{
}


TileAnimator::~TileAnimator()
{
}

void TileAnimator::tick() {

}

sf::Texture TileAnimator::getTexture()
{
	return texture;
}

void TileAnimator::setTexture(sf::Texture t)
{
	sprite.setTexture(texture);
}

sf::Sprite TileAnimator::getSprite()
{
	
	sprite.setTextureRect(sf::IntRect(texturePosX, texturePosY, spriteSizeX, spriteSizeY));
	return sprite;
}
