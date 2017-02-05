#ifndef __StateManager__
#define __StateManager__

#include "SFML\Graphics.hpp"
#include "State.h"
#include "GameState.h"
#include "../Renderer/GameRenderer.h"

class StateManager {
public:
	StateManager();
	~StateManager();
	void run();
private:
	const int FPS = 60;
	sf::RenderWindow window;
	State *currentState;
	//GameRenderer *renderer;
	
};

#endif
