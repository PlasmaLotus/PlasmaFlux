#include "Game.h"
Game::Game() {
	init();
}

Game::~Game() {

}

void Game::init() {
	//renderer;
	level.loadLevel("assets/levels/debug.lvl");
}
Level *Game::getLevel()
{
	return &level;
}

Player Game::getPlayer() {
	return player;
}

void Game::tick() {
	physics.handlePlayerPhysics(player);
}
void Game::render() {
	//renderer.render(level);
}