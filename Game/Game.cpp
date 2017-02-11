#include "Game.h"
Game::Game() {
	init();
}

Game::~Game() {

}

void Game::init() {
	//renderer;
	level.loadLevel("assets/levels/debug.lvl");
	player.setPosition(16, 16);
}
Level *Game::getLevel()
{
	return &level;
}

Player *Game::getPlayer() {
	return &player;
}

void Game::tick() {
	physics.handlePlayerPhysics(player, level);
}
void Game::render() {
	//renderer.render(level);
}