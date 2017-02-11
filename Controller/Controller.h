#ifndef _Controller_H_
#define _Controller_H_

//#include "SFML\Window.hpp"
#include "ControllerConfig.h"
#include "../Game/Player.h"


class Controller {
public:

	Controller();
	Controller(Player *b);
	~Controller();
	void updateConfig();
	void handleInput();
	void setPlayer(Player *b);

private:
	Player *player;

	ControlMode mode;
	ControllerConfig config;
	void handleCommand(ControllerCommand command);
	bool swapHeld;
	int swapHeldCounter;
	bool *buttonHeld;

};

#endif // _Controller_H_
