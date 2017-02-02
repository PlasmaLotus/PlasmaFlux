
#ifndef __Player__
#define __Player__

class Player {
public:

	Player();
	~Player();
	void ok();
	enum State{Idle, Walking, Running, Jumping, Landing};
	struct Vec {
		float x, y;
	};
	struct Position {
		int x, y;
	};
private:
	Vec velocity;
	const float jmp = -6;
	const float topXSpeed = 6;
	const float topYSpeed = 16;
	const float gravity = 0.21875;
	Position position;
};
#endif