
#ifndef __Player__
#define __Player__

class Player {
public:

	Player();
	~Player();
	void ok();
	enum State{Idle, Walking, Running, Jumping, Landing};
private:

};
#endif