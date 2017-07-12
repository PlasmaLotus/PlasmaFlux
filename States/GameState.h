#ifndef __GameState__
#define __GameState__

#include "State.h"
#include "../Game/Game.h"
#include "../Renderer/GameRenderer.h"
#include "SFML\Graphics.hpp"
#include "../Controller/Controller.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow *w);

	virtual ~GameState();
	virtual void tick();
	Game *getGame();
	//StateManager& stateManager;
private:
	Game *game;
	GameRenderer *renderer;
	sf::RenderWindow* window;
	Controller *p1Controller;

};

#endif
