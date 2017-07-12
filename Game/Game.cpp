#include "Game.h"
Game::Game() {
	init();
}

Game::~Game() {

}

void Game::init() {
	//renderer;
	level.loadLevel("assets/levels/debug.lvl");
	player.init(32, 13*16);
	//player.setPosition(32, 32);
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
	frame++;
}
void Game::render() {
	//renderer.render(level);
}