#include "GameState.h"

GameState::GameState(sf::RenderWindow *w):
	State(),
	game(NULL),
	renderer(NULL),
	window(w)
{
	game = new Game();
	renderer = new GameRenderer(window, game);
	//renderer = new GameRenderer();
	//renderer->addGame(game);
	//renderer->addWindow(window);
	p1Controller = new Controller(game->getPlayer());
}

GameState::~GameState()
{
	delete game;
	delete renderer;
	delete p1Controller;
}

void GameState::tick()
{
	//getinput here
	p1Controller->handleInput();
	game->tick();
	renderer->render();
	//printf("FPS: %d\n", stateManager->getFPS());
	
}

Game * GameState::getGame()
{
	return game;
}


