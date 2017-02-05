#ifndef __Game_Renderer__
#define __Game_Renderer__

#include "SFML\Graphics.hpp"
#include "Level.h"
#include "Game.h"
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
	void _drawLevel();
	void _drawCharacters();
	void display();

	void addWindow(sf::RenderWindow * w);

	void addGame(Game * g);

private:
	Game *game;
	sf::RenderWindow *window;
};

#endif
