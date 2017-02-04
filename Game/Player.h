
#ifndef __Player__
#define __Player__

//#include "PhysicsManager.h"
struct Vec {
	float x, y;
};
struct Position {
	int x, y;
};

class Player {
public:
	
	Player();
	~Player();
	void tick();
	enum State{Idle, Walking, Running, Jumping, Landing};

	Vec *getNextPos();
	float getNextXPos();
	float getNextYPos();
	bool i;
	void left();
	void right();
	void jump();
	//Positive is Right and Down
private:
	Vec velocity;
	float ySpeed;
	float xSpeed;
	bool isJumping();
	
	const float jmp = -6;
	const float topXSpeed = 6;
	const float topYSpeed = -16;
	const float gravity = 0.21875;
	Vec nextPos;
	Vec prevPos;
};
#endif