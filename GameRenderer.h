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

	bool loadTextures();
	void setWindowSize(int width, int height);

	void render();
	void render(Level &level);
	void clear();
	void draw();
	void setTilesTextures();
	void setCenter();
	//void _draw(Level &level);
	void _drawLevel();
	void _drawCharacters();
	void display();

	void addWindow(sf::RenderWindow * w);

	void addGame(Game * g);

private:
	const int originalWindowWidth = 240;
	const int originalWindowHeight = 160;
	int windowWidth = 240;
	int windowHeight = 160;
	int spriteSizeX;
	int spriteSizeY;

	Game *game;
	sf::RenderWindow *window;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture tilesTexture;
	sf::Texture playerTexture;

	sf::RenderTexture windowTexture;
	sf::View mainView;
	//sf::View view(sf::FloatRect(0, 0, 1000, 600));
	/* 10 / 15 */

	sf::Sprite onScreenSprites[11][16];
};

#endif
