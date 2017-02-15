
#ifndef __Player__
#define __Player__

//#include "PhysicsManager.h"
struct Vec {
	float x, y;
};
struct Position {
	int x, y;
};

struct Bounds {
	int up, down, left, right;
};

class Player {
public:
	
	Player();
	~Player();
	void tick();
	enum MovementState{Idle, Walking, Running};
	enum AirState { Grounded, Jumping, Airborne, Falling, MaxFalling, Landing };
	//enum AirState{FreeFalling, MaxFalling};

	void init(float x, float y);
	void setPosition(float x, float y);
	void movePosition(float x, float y);

	//void setYSpeed(float speed);
	
	Vec *getNextPos();
	float getNextXPos();
	float getNextYPos();
	Vec *getPrevPos();
	float getPrevXPos();
	float getPrevYPos();
	Bounds getNextBounds();
	Bounds getPrevBounds();
	int getBBoxSizeX();
	int getBBoxSizeY();
	void isOnGround(bool b);
	
	void left();
	void right();
	void up();
	void down();
	void action();
	void jump();
	//Positive is Right and Down
private:
	Vec velocity;
	float ySpeed = 0.0;
	float xSpeed = 0.0;
	bool isJumping();
	bool isJmping = false;
	bool onGround = false;
	bool facingRight = true;
	MovementState xState = Idle;
	AirState yState = Grounded;
	
	/*Constants*/
	const float xAccel = 0.046875;
	const float xDecel = 0.45;//0.5;

	const float baseFriction = 0.046875;
	const float waterFriction = 0.125;
	const float iceFriction = 0.016875;

	const float topRunSpeed = 6.0;
	const float topWalkSpeed = 4.0;
	const float jmp = -6.0;//-11.0;
	const float topWalkingSpeed = 3.0;
	const float topXSpeed = 6.0;
	const float topYSpeed = 2.0;//speed down 6 for kirby(at 30f/s), 16 for Sonic
	//lul ok mte
	const float gravity = 0.367;//0.21875/3;
	float jumpAccel = jmp;
	int jumpFrames = 180;
	int jumpCounter = 0;
	//const float gravity = 0.105;
	Vec nextPos;//Top Left Edge
	Vec prevPos;//Top Left edge
	int time = 0;
	int boundingBoxSizeX = 16;
	int boundingBoxSizeY = 16;

};
#endif