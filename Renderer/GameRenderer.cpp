#include "GameRenderer.h"
GameRenderer::GameRenderer() {

}
GameRenderer::GameRenderer(sf::RenderWindow *w, Game *g):
game(NULL),
window(NULL){
	window = w;
	game = g;
}
GameRenderer::~GameRenderer() {

}

void GameRenderer::render() {
	clear();
	//_draw(Level level);
	draw();
	display();

}
void GameRenderer::render(Level &level) {
	clear();
	_draw(level);
	draw();
	display();

}

void GameRenderer::clear() {
	system("cmd /c cls");
}
void GameRenderer::draw() {
	_drawLevel();
	_drawCharacters();


}

void GameRenderer::_drawLevel() {
	Level *lvl = game->getLevel();
	for (int i = 0; i < lvl->levelHeight; i++) {
		for (int j = 0; j < lvl->levelWidth; j++) {
			if (lvl->getColTile(i, j))
			{
				//if there is a tile
				printf("0");
			}
			else
			{
				printf(" ");
			}

		}
		printf("\n");
	}
}

void GameRenderer::_drawCharacters() {

}

void GameRenderer::display() {

}

void GameRenderer::addWindow(sf::RenderWindow *w) {
	window = w;
}
void GameRenderer::addGame(Game *ga) {
	game = ga;
}