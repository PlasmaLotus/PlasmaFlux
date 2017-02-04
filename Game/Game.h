#ifndef __Game__
#define __Game__

#include "SFML\Graphics.hpp"
#include "GameRenderer.h"
//#include "../Controller/Controller.h"
#include "Level.h"
#include "Player.h"

class Game {
public:
	Game();
	Game(sf::RenderWindow &w);
	~Game();

	void init();

	void run();
	
	Level getLevel();



private:
	GameRenderer renderer;
	sf::RenderWindow *window;
	//Controller p1Controller;
	Level level;
	const int FPS = 60;
	void tick();

	void render();
};

#endif
