#include "Player.h"

Player::Player() {

}
Player::~Player(){

}


void Player::setPosition(float x, float y) {
	nextPos = { x, y };
	//prevPos = { x, y };
}

void Player::movePosition(float x, float y) {
	nextPos.x += x;
	nextPos.y += y;
}

void Player::setYSpeed(float speed) {
	ySpeed = speed;
}

void Player::tick() {
	//onGround = false;
	//if (time == 43)
	//{
		//int j = time;
	//}
	//handle collisions?


	prevPos = nextPos;
	//add gravity
	/*
	ySpeed += jumpAccel;
	
	if (--jumpCounter <= 0) {
		jumpAccel = 0;
	}
	else
	{
		jumpAccel  = jumpAccel *3 /4;
	}
	*/

	ySpeed += gravity;
	if (ySpeed > topYSpeed)
	{
		ySpeed = topYSpeed;
	}

	if (xSpeed > topXSpeed)
	{
		xSpeed = topXSpeed;
	}

	nextPos.x += xSpeed;
	nextPos.y += ySpeed;
	
	if (onGround)
	{
		ySpeed = 0.0;
		isJmping = false;
	}

	

	//if (nextPos.x >= 200)
		//int i = nextPos.x;

	time++;
}

void Player::left() {

}
void Player::right()
{
}
void Player::up() {

}
void Player::down()
{
}
void Player::action() {

}

void Player::jump() {
	if (!isJumping())
	{
		if (ySpeed < 0)//if moving upwards
		{
			/*
			if (ySpeed < -4)
			{
			ySpeed = -4;
			}
			*/

		}
		else if (ySpeed == 0)
		{
			ySpeed = jmp;
			//jumpCounter = jumpFrames;
			isJmping = true;
			onGround = false;
		}
		else if (ySpeed > 0)
		{

		}
	}
	
}

bool Player::isJumping() {

	return isJmping;
}

Vec *Player::getNextPos()
{
	return &nextPos;
}

float Player::getNextYPos() {
	return nextPos.y;
}

float Player::getNextXPos() {
	return nextPos.x;
}

Vec *Player::getPrevPos()
{
	return &prevPos;
}

float Player::getPrevYPos() {
	return prevPos.y;
}

float Player::getPrevXPos() {
	return prevPos.x;
}
/*
float Player::getUpBBoxPoint(){
}
float Player::getDownBBoxPoint() {}
float Player::getLeftBBoxPoint() {}
float Player::getRightBBoxPoint() {}
*/
Bounds Player::getNextBounds() {
	struct Bounds b;
	b.left = nextPos.x;
	b.down = nextPos.y+ boundingBoxSizeY-1;
	b.right = nextPos.x + boundingBoxSizeX-1;
	b.up = nextPos.y;
	return b;
}

Bounds Player::getPrevBounds() {
	struct Bounds b;
	b.left = prevPos.x;
	b.down = prevPos.y + boundingBoxSizeY-1;
	b.right = prevPos.x + boundingBoxSizeX-1;
	b.up = prevPos.y;
	return b;
}
int Player::getBBoxSizeX() {
	return boundingBoxSizeX;
}
int Player::getBBoxSizeY() {
	return boundingBoxSizeY;
}

void Player::isOnGround(bool b) {
	onGround = b;
}