#include "Player.h"

Player::Player() {

}
Player::~Player(){

}
void Player::tick() {
	//handle collisions?
	prevPos = nextPos;
	//add gravity
	ySpeed += gravity;
	if (ySpeed < topYSpeed)
	{
		ySpeed = topYSpeed;
	}

	nextPos.x += xSpeed;
	nextPos.x += ySpeed;


}

void Player::left() {

}
void Player::right()
{
}
void Player::jump() {

	if (ySpeed < 0)//if moving upwards
	{
		if (ySpeed < -4)
		{
			ySpeed = -4;
		}
	}
	else if (ySpeed == 0)
	{
		ySpeed = jmp;
	}
	else if (ySpeed > 0)
	{

	}
}

bool Player::isJumping() {

	return false;
}

Vec *Player::getNextPos()
{
	return &nextPos;
}

float Player::getNextYPos() {
	return nextPos.y;
}

float Player::getNextXPos() {
	return nextPos.y;
}
