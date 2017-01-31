#ifndef __Game__
#define __Game__

#include "SFML\Graphics.hpp"
#include "GameRenderer.h"

class Game {
public:
	Game();
	Game(sf::RenderWindow &w);
	~Game();

	void init();

	void run();


private:
	GameRenderer renderer;
	sf::RenderWindow *window;

};

#endif
