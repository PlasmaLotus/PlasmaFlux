#ifndef __Game_Renderer__
#define __Game_Renderer__

#include "SFML\Graphics.hpp"
#include "../Game/Level.h"
#include "../Game/Game.h"
#include <stdio.h>
class GameRenderer {
public:
	GameRenderer();
	GameRenderer(sf::RenderWindow * w, Game * g);
	~GameRenderer();

	void render();
	void render(Level &level);
	void clear();
	void draw();
	void _draw(Level &level);
	void display();

	void addWindow(sf::RenderWindow * w);

	void addGame(Game * g);

private:
	Game *game;
	sf::RenderWindow *window;
};

#endif
