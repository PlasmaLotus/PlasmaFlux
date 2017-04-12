#include "GameRenderer.h"
#include "../main.h"
GameRenderer::GameRenderer() {

}
GameRenderer::GameRenderer(sf::RenderWindow *w, Game *g):
game(NULL),
window(NULL){
	window = w;
	game = g;
	mainView.reset(sf::FloatRect(0, 0, originalWindowWidth, originalWindowHeight));
	window->setView(mainView);
	loadTextures();
	spriteSizeX = game->getLevel()->TILESIZEX;
	spriteSizeY = game->getLevel()->TILESIZEY;
}
GameRenderer::~GameRenderer() {

}

bool GameRenderer::loadTextures() {
	//windowTexture.set
	//backgroundSprite.setScale()
	if (!backgroundTexture.loadFromFile("assets/images/bg1.png"))
	{
		printf("ripBG");
		return false;
	}
	if (!tilesTexture.loadFromFile("assets/images/blocks.png"))
	{
		printf("ripBlocks");
		return false;
	}
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

void GameRenderer::setTilesTextures() {

}

void GameRenderer::setCenter() {
	Vec *pos = game->getPlayer()->getPrevPos();
	float centerX, centerY;
	if (pos->x < mainView.getSize().x / 2)
		centerX = mainView.getSize().x / 2;
	else if (pos->x > game->getLevel()->levelWidth*spriteSizeX - mainView.getSize().x / 2)
		centerX = game->getLevel()->levelWidth*spriteSizeX - mainView.getSize().x / 2;
	else
		centerX = pos->x;
	
	
	if (pos->y < mainView.getSize().y / 2)
		centerY = mainView.getSize().y / 2;
	else if (pos->y > game->getLevel()->levelHeight*spriteSizeY - mainView.getSize().y / 2)
		centerY = game->getLevel()->levelHeight*spriteSizeY - mainView.getSize().y / 2;
	else
		centerY = pos->y;

	mainView.setCenter({ centerX, centerY });
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
	float x = player->getPrevXPos();
	float y = player->getPrevYPos();
	printf("Player Pos: %3.3f - %3.3f \n", x, y);
	printf("Tile :%3.0f - %3.0f of %d - %d \n", x / 16, y / 16, lvl->levelWidth-1, lvl->levelHeight-1);
	printf("xSpeed: %3.4f    \n", player->getXSpeed());
	printf("ySpeed: %3.4f    \n", player->getYSpeed());
	/*Test*/

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