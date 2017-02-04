#ifndef __Game_Renderer__
#define __Game_Renderer__

#include "SFML\Graphics.hpp"
#include "Level.h"
#include "Game.h"
#include <stdio.h>
class GameRenderer {
public:
	GameRenderer();
	GameRenderer(sf::RenderWindow &w);
	~GameRenderer();

	void render();
	void render(Level &level);
	void clear();
	void draw();
	void _draw(Level &level);
	void display();


private:
	Game *game;
	//Level *level;
};

#endif
