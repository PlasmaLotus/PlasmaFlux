#include "GameState.h"

GameState::GameState(sf::RenderWindow *w):
	game(NULL),
	renderer(NULL),
	window(w)
{
	game = new Game();
	//renderer = new GameRenderer(window, game);
	renderer = new GameRenderer();
	renderer->addGame(game);
	renderer->addWindow(window);
}

GameState::~GameState()
{
	delete game;
	delete renderer;
}

void GameState::tick()
{
	//getinput here
	game->tick();
	renderer->render();
}

Game * GameState::getGame()
{
	return game;
}


