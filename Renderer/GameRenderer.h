#ifndef __Game_Renderer__
#define __Game_Renderer__

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "../Game/Level.h"

#include "../Game/Game.h"
#include "../Game/Player.h"
#include "../Animator/PlayerAnimator.h"
#include <stdio.h>
#include <iostream>


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
	void initAllTilesSprites(int nbTiles);
	void setTilesTextures();
	void setCenter();
	//void _draw(Level &level);
	void _drawLevel();
	void _drawLevelFull();
	void _drawLevelFullPoint();
	void _drawCharacters();
	void _drawPlayer();
	void display();

	void addWindow(sf::RenderWindow * w);
	void setAllTilesTextures();
	void addGame(Game * g);

private:
	const int originalWindowWidth = 240;
	const int originalWindowHeight = 160;
	int windowWidth = 240;
	int windowHeight = 160;
	int spriteSizeX = 16;
	int spriteSizeY = 16;

	Game *game;
	sf::RenderWindow *window;
	PlayerAnimator pAnimator;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture tilesTexture;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::RenderTexture windowTexture;
	sf::View mainView;
	//sf::View view(sf::FloatRect(0, 0, 1000, 600));
	/* 10 / 15 */
	int nbTilesX = 16;
	int nbTilesY = 11;
	int currentOnScreenTileX = 0;
	int currentOnScreenTileY = 0;
	sf::Sprite onScreenSprites[16][11];
	//sprites dimentions: 16x10

	sf::Sprite test[16][16];
	//sf::Sprite* allTilesSprites;
	sf::Sprite allTilesSprites[265][265];
	sf::Sprite * _allTilesSprites;
	int debug = 0;
	int _debug();
	void loadLevel(Level & level);
};

#endif
