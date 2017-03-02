#include "Player.h"

Player::Player() {

}
Player::~Player(){

}

void Player::init(float x, float y) {
	nextPos = { x, y };
	prevPos = { x, y };
}
void Player::setPosition(float x, float y) {
	nextPos = { x, y };
	//prevPos = { x, y };
}

void Player::movePosition(float x, float y) {
	nextPos.x += x;
	nextPos.y += y;
}

/*
void Player::setYSpeed(float speed) {
	ySpeed = speed;
}
*/

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
	if (xState == Idle) {
		if (facingRight) {
			xSpeed -= baseFriction;
			if (xSpeed <= 0) {
				xSpeed = 0.0;
			}
		}
		else {
			xSpeed += baseFriction;
			if (xSpeed >= 0) {
				xSpeed = 0.0;
			}
		}
	}
	
	if (!onGround)
		ySpeed += gravity;
	if (ySpeed > topYSpeed)
	{
		ySpeed = topYSpeed;
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

	/*Put back to 0 if speed is close to 0*/
	/*
	if (xSpeed <= 0.001 && xSpeed >= -0.001)
	{
		xSpeed = 0.0000;
	}
	if (ySpeed <= 0.001 && ySpeed >= -0.001)
	{
		ySpeed = 0.0000;
	}
	*/
	time++;
	xState = Idle;
}

void Player::left() {
	if (!facingRight)
	{
		xSpeed -= xAccel;
		if (xSpeed*-1 >= topRunSpeed) {
			xSpeed = topRunSpeed*-1;
		}
	}
	else
	{
		//if facing right
		xSpeed -= xDecel;
		if (xSpeed < 0)
			facingRight = false;
	}
	xState = Running;
}
void Player::right(){
	if (facingRight)
	{
		xSpeed += xAccel;
		if (xSpeed >= topRunSpeed) {
			xSpeed = topRunSpeed;
		}
	}
	else
	{
		xSpeed += xDecel;
		if (xSpeed > 0)
			facingRight = true;
	}
	xState = Running;
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

float Player::getXSpeed() {
	return xSpeed;
}

float Player::getYSpeed() {
	return ySpeed;
}
