#include "GameRenderer.h"
#include "../main.h"
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
	//_draw(level);
	draw();
	display();

}

void GameRenderer::clear() {
	//system("cmd /c cls");
	gotoxy(0, 0);
}
void GameRenderer::draw() {
	_drawLevel();
	_drawCharacters();


}

void GameRenderer::_drawLevel() {
	Player *player = game->getPlayer();
	Level *lvl = game->getLevel();

	int plX = player->getPrevXPos() / 16;
	int plY = player->getPrevYPos() / 16;
	for (int i = 0; i < lvl->levelHeight; i++) {
		for (int j = 0; j < lvl->levelWidth; j++) {
			if (plY == i && plX == j) {
				printf("P");
			}
			else if (lvl->getColTile(i, j))
			{
				//if there is a tile
				//printf("%d", lvl->getTile(i, j)->getID());
				//printf("%f", lvl->getTile(i, j)->getAngle());

				if (lvl->getTile(i, j)->isWater())
				{
					printf("o");
				}
				else
					printf("1");
			}
			else
			{
				printf("_");
			}

		}
		printf("\n");
	}
}

void GameRenderer::_drawCharacters() {
	Player *player = game->getPlayer();
	
}

void GameRenderer::display() {

}

void GameRenderer::addWindow(sf::RenderWindow *w) {
	window = w;
}
void GameRenderer::addGame(Game *ga) {
	game = ga;
}