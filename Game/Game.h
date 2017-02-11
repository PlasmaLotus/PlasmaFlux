#ifndef __Game__
#define __Game__

#include "SFML\Graphics.hpp"
//#include "../Controller/Controller.h"
#include "Level.h"
#include "Player.h"
#include "PhysicsManager.h"

class Game {
public:
	Game();
	//Game(sf::RenderWindow &w);
	~Game();

	void init();

	//void run();
	void tick();
	
	Level *getLevel();
	Player *getPlayer();


private:
	//GameRenderer renderer;
	sf::RenderWindow *window;
	//Controller p1Controller;
	PhysicsManager physics;
	Level level;
	const int FPS = 60;

	Player player;
	

	void render();
};

#endif
