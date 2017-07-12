#ifndef __StateManager__
#define __StateManager__

#include "SFML\Graphics.hpp"
#include "State.h"
#include "GameState.h"
#include "../Renderer/GameRenderer.h"

class StateManager {
public:
	static StateManager& getInstance();
	
	//static int calculatedFrameRate;
	void run();
	int getFPS();
	void showFPS();
private:
	StateManager();
	~StateManager();
	static const int FPS = 60;
	//int calcFPS = 60;
	sf::RenderWindow window;
	State *currentState;
	//GameRenderer *renderer;
	float time = 0.0f;
	int framesTime = 0;
	int calculatedFrameRate;
};

#endif
