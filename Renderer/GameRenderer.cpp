#include "GameRenderer.h"
#include "../main.h"
//#include "../States/StateManager.h"
GameRenderer::GameRenderer() {

}
GameRenderer::GameRenderer(sf::RenderWindow *w, Game *g):
game(NULL),
window(NULL){
	window = w;
	game = g;
	pAnimator.setPlayer(game->getPlayer());
	loadTextures();
	//mainView = window->getDefaultView();
	mainView.reset(sf::FloatRect(0, 0, originalWindowWidth, originalWindowHeight));
	//mainView.setViewport(sf::FloatRect(0, 0, 1, 1));
	//mainView.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));
	window->setView(mainView);
	//window->view
	
	spriteSizeX = game->getLevel()->TILESIZEX;
	spriteSizeY = game->getLevel()->TILESIZEY;

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 11; j++) {
			onScreenSprites[i][j].setTexture(tilesTexture);
		}
	}
	setTilesTextures();
	setAllTilesTextures();
}
GameRenderer::~GameRenderer() {
	//free(allTilesSprites);
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
	window->clear();
}
void GameRenderer::draw() {
	setCenter();
	//setTilesTextures();
	//_drawBackground();
	_drawLevel();
	_drawLevelFull();
	//_drawLevelFullPoint();
	//_drawForeGround();
	_drawCharacters();
	
}

bool GameRenderer::loadTextures() {
	//windowTexture.set
	//backgroundSprite.setScale()
	bool load = true;
	tilesTexture.setRepeated(true);
	playerTexture.setRepeated(true);


	std::string tilesPath = "assets/images/BlocksUpdated.png";
	std::string playerPath = "assets/images/2664.png";
	std::string bgPath = "assets/images/bg1.png";
	//std::string testPath = "C:/Users/Lee-Stenio/Panel Pop/TACD C++/TACD Source Code/assets/images/BlocksUpdated.png";

	sf::Image image;
	image.create(16, 16, sf::Color::Magenta);

	if (!backgroundTexture.loadFromFile(bgPath))
	{
		printf("ripBG/n");
		load = false;
	}
	if (!tilesTexture.loadFromFile(tilesPath))
	{
		printf("ripBlocks/n");
		load = false;
		tilesTexture.loadFromImage(image, sf::IntRect(0, 0, 16, 16));
	}
	if (!playerTexture.loadFromFile(playerPath))
	{
		printf("ripBlocks/n");
		load = false;
		tilesTexture.loadFromImage(image, sf::IntRect(0, 0, 16, 16));
	}
	
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			test[i][j].setTexture(tilesTexture);
		}
	}
	//setAllTilesTextures();
	playerSprite.setTexture(playerTexture);
	return load;
}

void GameRenderer::setWindowSize(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
}



void GameRenderer::initAllTilesSprites(int nbTiles){

	_allTilesSprites = (sf::Sprite*)malloc(nbTiles* sizeof(sf::Sprite));
	for (int i = 0; i > nbTiles; i++) {
		//allTilesSprites[i].setPosition(0, 0);
		_allTilesSprites[i] = sf::Sprite::Sprite();
		_allTilesSprites[i].setTexture(tilesTexture);
	}
	
}

void GameRenderer::setTilesTextures() {
	Player *player = game->getPlayer();
	Level *lvl = game->getLevel();
	float playerPosX = player->getPrevXPos();
	float playerPosY = player->getPrevYPos();
	float nonsense = playerPosX + playerPosY;
	int px = 0; 
	int py = 0;
	int offsetX = 0;
	int offsetY = 0;
	
	
	//if (mainView.)
	if (window != NULL) {
		//px = mainView.getCenter().x - 8;
		//py = mainView.getCenter().y - 5;
		

		px = (int)player->getPrevXPos()/ 16  - nbTilesX/2;
		py = (int)player->getPrevYPos()/ 16  - nbTilesY/2;

		if (px < 0) {
			px = 0;
		}
		if (px + 16 > lvl->levelWidth) {
			px = lvl->levelWidth- 16;
		}
		if (py < 0) {
			px = 0;
		}
		if (py + 11 > lvl->levelHeight) {
			py = lvl->levelHeight - 11;
		}
		offsetX = (int)player->getPrevPos()->x % spriteSizeX;//
		//offsetY = (int)player->getPrevPos()->y % spriteSizeY;
		offsetY = 0;

		if (px <= 0) {
			offsetX = 0;
		}
		if (py <= 0) {
			offsetY = 0;
		}
		currentOnScreenTileX = px;
		currentOnScreenTileY = py;
	}

	///Setting Textures
	for (int i = px; i < px + nbTilesX-1; i++) {
		for (int j = py; j < py + nbTilesY-1; j++) {
			int spriteXit = px + nbTilesX - 1 - i;
			int spriteYit = py + nbTilesY - 1 - j;
			
			if (lvl->getTile(i, j) != NULL)
			{
				//test[i][j].setTexture
				//onScreenSprites[i][j].setTexture(tilesTexture);
				onScreenSprites[i][j].setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
				//test[i][j].setColor(sf::Color(255, 255, 255, 255));
			}
			else
			{
				//onScreenSprites[i][j].setTexture(tilesTexture);
				onScreenSprites[i][j].setTextureRect(sf::IntRect(32, 0, 0, 0));
			}

			

			onScreenSprites[i][j].setPosition(spriteXit*spriteSizeX - 8 + offsetX, spriteYit*spriteSizeY - 6 + offsetY);
		}
	}
	/*
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 11; j++) {
			if (lvl->getTile(i+ px/spriteSizeX, j+ py/spriteSizeY) != NULL)
			{
				//onScreenSprites[i][j].setTexture(tilesTexture);
				onScreenSprites[i][j].setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
				onScreenSprites[i][j].setColor(sf::Color(255, 255, 255, 255));
			}
			else
			{
				//onScreenSprites[i][j].setTexture(tilesTexture);
				onScreenSprites[i][j].setTextureRect(sf::IntRect(16, 16, spriteSizeX, spriteSizeY));
			}

			onScreenSprites[i][j].setPosition(offsetX, offsetY);
		}
	}
	*/
}
void GameRenderer::setAllTilesTextures() {
	Level* level = game->getLevel();
	int nbTiles = level->levelWidth*level->levelHeight;
	initAllTilesSprites(nbTiles);
	int XaxisOffset = 8;

	for (int i = 0; i < level->levelHeight; i++) {
		for (int j = 0; j < level->levelWidth; j++) {


			//int tileX = i / level->levelWidth;
			//int tileY = i%level->levelHeight;
			//allTilesSprites[level->levelWidth *tileX + tileY] = sf::Sprite::Sprite();

			/*Basic textures*/
			allTilesSprites[i][j].setTexture(tilesTexture);
			if (level->getTile(i, j) != NULL)
			{
				//allTilesSprites[level->levelWidth *tileX +tileY].setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
				allTilesSprites[i][j].setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
				//allTilesSprites[i][j].setRotation(45.0f);
			}
			else
			{
				//allTilesSprites[level->levelWidth *tileX + tileY].setTextureRect(sf::IntRect(32, 0, 0, 0));
				allTilesSprites[i][j].setTextureRect(sf::IntRect(32, 0, spriteSizeX, spriteSizeY));

			}

			allTilesSprites[i][j].setPosition(i *spriteSizeX, j*spriteSizeY);
			//- XaxisOffset
			debug++;
			if (i == 20) {
				debug = 0;
			}
		}
	}
	_debug();

	/*AllTiles Pointers*/
	for (int i = 0; i < level->levelHeight * level->levelWidth; i++) {
	
			int tileX = i / level->levelWidth;
			int tileY = i%level->levelHeight;
			//_allTilesSprites[level->levelWidth *tileX + tileY] = sf::Sprite::Sprite();

			/*Basic textures*/
			_allTilesSprites[i].setTexture(tilesTexture);
			if (level->getTile(tileX, tileY) != NULL)
			{
				_allTilesSprites[level->levelWidth *tileX +tileY].setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
				//allTilesSprites[i][j].setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

			}
			else
			{
				_allTilesSprites[level->levelWidth *tileX + tileY].setTextureRect(sf::IntRect(32, 0, 0, 0));
				//allTilesSprites[i][j].setTextureRect(sf::IntRect(32, 0, spriteSizeX, spriteSizeY));

			}

			_allTilesSprites[level->levelWidth *tileX + tileY].setPosition(tileX *spriteSizeX - 8, tileY*spriteSizeY);
			debug++;
	}

}

void GameRenderer::setCenter() {
	//Vec *pos = game->getPlayer()->getPrevPos();
	float posX = game->getPlayer()->getPrevXPos();
	float posY = game->getPlayer()->getPrevYPos();
	float centerX, centerY;
	if (posX < mainView.getSize().x / 2)
		centerX = mainView.getSize().x / 2;
	else if (posX > game->getLevel()->levelWidth*spriteSizeX - mainView.getSize().x / 2)
		centerX = game->getLevel()->levelWidth*spriteSizeX - mainView.getSize().x / 2;
	else
		centerX = posX;
	
	
	if (posY < mainView.getSize().y / 2)
		centerY = mainView.getSize().y / 2;
	else if (posY > game->getLevel()->levelHeight*spriteSizeY - mainView.getSize().y / 2)
		centerY = game->getLevel()->levelHeight*spriteSizeY - mainView.getSize().y / 2;
	else
		centerY = posY;

	mainView.setCenter(sf::Vector2f(centerX, centerY));
	mainView.setViewport(sf::FloatRect(sf::Vector2f( centerX, centerY ), sf::Vector2f(originalWindowWidth, originalWindowHeight)));
	//mainView.setCenter(sf::Vector2f(0, 0));
	
	//mainView.setSize(originalWindowWidth, originalWindowHeight);
	//mainView.rotate(1.0f);
	//mainView.setRotation(30.0f);
	//mainView.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));
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
				/*
				if (lvl->getTile(i, j)->isWater())
				{
					printf("o");
				}
				else
				*/
				printf("1");
			}
			else
			{
				printf("_");
			}
		}
		printf("\n");
	}

	//printf("%d\n", sizeof(sf::Sprite));
	float x = player->getPrevXPos();
	float y = player->getPrevYPos();
	//printf("FPS: %d", StateManager::getFPS());
	printf("Player Pos: %3.3f - %3.3f \n", x, y);
	printf("Tile :%3.0f - %3.0f of %d - %d \n", x / 16, y / 16, lvl->levelWidth - 1, lvl->levelHeight - 1);
	printf("xSpeed: %3.4f    \n", player->getXSpeed());
	printf("ySpeed: %3.4f    \n", player->getYSpeed());
	

}

void GameRenderer::_drawLevelFull() {
	Level *level = game->getLevel();

	/*Test*/
	/*
	for (int i = 0; i < nbTilesX; i++) {
	for (int j = 0; j < nbTilesY; j++) {
	window->draw(onScreenSprites[i][j]);
	//window->draw(test[i][j]);
	}
	}
	*/
	/*AllSprites*/
	//int ok;
	/*
	for (int i = 0; i < level->levelWidth*level->levelHeight; i++) {
	
			debug = i;
			window->draw(_allTilesSprites[i]);
			//window->draw(onScreenSprites)
			//window->draw(test[i][j]);	
		
	}
	*/
	for (int i = 0; i < level->levelHeight; i++) {
		for (int j = 0; j < level->levelWidth; j++) {
			debug = i*j;
			window->draw(allTilesSprites[i][j]);
		}
	}

}

void GameRenderer::_drawCharacters() {
	_drawPlayer();
	//_drawEnemies()
}
void GameRenderer::_drawPlayer(){
	Player *player = game->getPlayer();
	//player
	//sf::Sprite pSprite;// = pAnimator.getSprite();
	//sf::Texture pTextu = pAnimator.getTexture();
	//pSprite.setTexture(pTextu);
	//playerSprite.set
	//playerSprite.setTexture(tilesTexture);
	playerSprite.setTextureRect(
		sf::IntRect(pAnimator.getTexturePosX(), pAnimator.getTexturePosY(), 
			pAnimator.getWidth(), pAnimator.getHeight())	);
	//playerSprite.setPosition(player->getPrevXPos()-currentOnScreenTileX*spriteSizeX, player->getPrevYPos() - currentOnScreenTileY*spriteSizeY);
	
	//playerSprite.setPosition(pAnimator.getPosX(), pAnimator.getPosY());
	playerSprite.setPosition(player->getPrevXPos(), player->getPrevYPos());

	window->draw(playerSprite);
	//sf::Sprite *s = pAnimator.getSpriteP();
	//window->draw(*(s));
	//window->draw(pAnimator.getSprite());
}

void GameRenderer::display() {
	window->display();
}

void GameRenderer::addWindow(sf::RenderWindow *w) {
	window = w;
}
void GameRenderer::addGame(Game *ga) {
	game = ga;
}

int GameRenderer::_debug()
{
	return debug;
}

void GameRenderer::loadLevel(Level &level) {
	//something
}