#include "GameRenderer.h"
GameRenderer::GameRenderer() {

}
GameRenderer::GameRenderer(sf::RenderWindow &w) {

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

}

void GameRenderer::_draw(Level &level) {
	Tile *t;
	for (int i = 0; i < level.levelWidth; i++) {
		for (int j = 0; j < level.levelHeight; j++) {
			t = level.getTile(i, j);
			if (t != NULL)
			{
				//if there is a tile
				printf("1");
			}
			else
			{
				printf(" ");
			}

		}
		printf("\n");
	}
}
void GameRenderer::display() {

}
