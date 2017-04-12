#include "Level.h"


Level::Level():
levelHeight(0),
levelWidth(0),
initiated(false){
}
Level::~Level(){
	
	if (initiated)
	{
		for (int i = 0; i < levelHeight; i++) {
			for (int j = 0; j < levelWidth; j++) {
				//tileset[i][j] = (Tile*)malloc;
				//delete tileset[i][j];
				if (tileset[i][j] != NULL)
				{
					clearTile(i, j);
					//free(tileset[i][j]);
				}
			}
		}
		for (int i = 0; i < levelHeight; i++)
		{
			free(tileset[i]);
			delete colTileset[i];

			free(tileSet_[i]);
		}
		free(tileset);
		delete colTileset;

		free(tileSet_);
	}
}

bool Level::loadLevel(std::string levelName) {

	levelAttributes state;
	unsigned int tilesX = 0;
	unsigned int tilesY = 0;

	std::fstream file;
	file.open(levelName);

	if (file.is_open()) {

		std::string text;
		while (!file.eof())
		{
			std::getline(file, text);
			if (text != "")
			{

				if (text.at(0) == '[')
				{
					//change state
					//std::string textState;
					text = text.substr(1);
					text.erase(text.find(']'));
					if (text == "Dimensions")
					{
						state = Dimensions;
					}
					else if (text == "ScrollLock")
					{
						state = ScrollLock;
					}
					else if (text == "Level")
					{
						state = levelAttributes::Tiles;
					}

				}
				else {
					switch (state)
					{
					case levelAttributes::Tiles:
					{
						/**/
						if (levelHeight > 0 && levelWidth > 0)
						{
							bool water = false;
							int id = 0;
							float angle = 0;
							TileType type = TileType::SolidBlock;
							initTileset();///Initiate Tileset Here
							initColTileset();
							/*setThe Tileset here*/
							std::string tileText = text;
							for (int i = 0; i < levelWidth; i++) {
								for (int j = 0; j < levelHeight; j++) {
									if (tileText == "")
									{
										break;
									}
									water = false;
									id = 0;
									angle = 0;

									/*Finding quotes in the text*/
									// 1 means there is a tile
									//if (tileText.find("block")!= std::string::npos)
									if (tileText.at(0) == '1')
									{
										//tileset[i][j] = new Tile();
										//Create a tile at this position
										if (tileText.find("w") != std::string::npos)
										{
											//tile Water
											water = true;
										}

										if (tileText.find("x") != std::string::npos)
										{
											//tile ID
											int tt = tileText.find("x") +1;
											int tf = tileText.find_first_of(" ", tt);
											//std::string idT
											id = atoi(tileText.substr(tt, tf).c_str());
										}

										if (tileText.find("o") != std::string::npos)
										{
											//tile Angle
											int tt = tileText.find("o") +1;
											int tf = tileText.find_first_of(" ", tt);
											//std::string idT
											angle = atof(tileText.substr(tt, tf).c_str());
										}
										if (tileText.find("t") != std::string::npos) {
											int tt = tileText.find("o") + 1;
											int tf = tileText.find_first_of(" ", tt);
											//std::string typeText = tileText.substr(tt, tf);
											int lul = atoi(tileText.substr(tt, tf).c_str());
											/*
											switch (lul)
											{
											case 1:
												type = 
											}
											*/
										}
										//createTile(i, j);
										tileset[i][j] = new Tile(id, angle, water);
										tileSet_[i][j].tile = new Tile(id, angle, water);
										tileSet_[i][j].tAnimator = new TileAnimator();
										colTileset[i][j] = true;
									}
									else if (tileText.at(0) == '0') {
										if (tileText.find("w") != std::string::npos)
										{
											water = true;
											tileset[i][j] = new Tile(0, 0, water);
											tileSet_[i][j].tile = new Tile(0, 0, water);
											tileSet_[i][j].tAnimator = new TileAnimator();
											colTileset[i][j] = true;
										}

									}
									std::getline(file, tileText);
									while (tileText.at(0) == '-') {
										std::getline(file, tileText);
									}
								}
							}
						}
						
						if (text == "0")
						{
							//pass to next tile
							state == levelAttributes::Tiles;
						}

						break;
					}
					case levelAttributes::Dimensions:
					{

						if (text.find("width") != std::string::npos || text.find("lengh") != std::string::npos)
						{
							std::string sub = text.substr(text.find('=') + 1);
							levelHeight = atoi(sub.c_str());
						}
						if (text.find("height") != std::string::npos)
						{
							std::string sub = text.substr(text.find('=') + 1);
							levelWidth = atoi(sub.c_str());
						}

						break;
					}
					default:
						break;
					}
				}
			}
			else
			{
				//if there is no texte
				if (state == levelAttributes::Tiles)
				{
					tilesX++;
					if (tilesX > levelWidth - 1)
					{
						tilesY++;
						tilesX = 0;
					}

				}
			}

		}


	}
	else
	{
		printf("unable to open %s\n", levelName);
		return false;
	}

}

bool Level::initLevel() {

	testInit();


	return false;
}

Tile * Level::getTile(int x, int y)
{
	if (tileset[x][y] != NULL)
	{
		return tileset[x][y];
	}
	else
	{
		return NULL;
	}
}

bool Level::getColTile(int x, int y)
{
	if (x < 0 || x >= levelWidth || y < 0 || y >= levelHeight)
		return true;
	else
		return colTileset[x][y];
	/*
	if (tileset[x][y] != NULL)
	{
		return tileset[x][y]->collidable();
	}
	else
	{
		return false;
	}
	*/
}

void Level::initTileset()
{
	tileset = (Tile***)malloc(levelHeight* sizeof(Tile**));
	for (int i = 0; i < levelHeight; i++)
	{
		tileset[i] = (Tile**)malloc(levelWidth* sizeof(Tile*));
	}
	for (int i = 0; i < levelHeight; i++) {
		for (int j = 0; j < levelWidth; j++) {
			//tileset[i][j] = (Tile*)malloc;
			//init all of them to null
			tileset[i][j] = NULL;
		}
	}



	tileSet_ = (TileInfo**)malloc(levelHeight* sizeof(TileInfo*));
	for (int i = 0; i < levelHeight; i++)
	{
		tileSet_[i] = (TileInfo*)malloc(levelWidth* sizeof(TileInfo));
	}
	for (int i = 0; i < levelHeight; i++) {
		for (int j = 0; j < levelWidth; j++) {
			//tileset[i][j] = (Tile*)malloc;
			//init all of them to null
			tileSet_[i][j].tAnimator = NULL;
			tileSet_[i][j].tile = NULL;
		}
	}

	initiated = true;
}

void Level::testInit() {

}

void Level::createTile(int x, int y)
{
	tileset[x][y] = new Tile();
	tileSet_[x][y].tile = new Tile();
	tileSet_[x][y].tAnimator = new TileAnimator();
}

void Level::clearTile(int x, int y)
{
	if (tileset[x][y] != NULL)
		delete tileset[x][y];

	if (tileSet_[x][y].tAnimator != NULL)
		delete(tileSet_[x][y].tAnimator);
	if (tileSet_[x][y].tile != NULL)
		delete(tileSet_[x][y].tile);
}

bool **Level::getCollisionTiles(){
	return colTileset;
}

void Level::debug(){
}

void Level::initColTileset(){
	colTileset = (bool**)malloc(levelHeight* sizeof(bool*));
	for (int i = 0; i < levelHeight; i++)
	{
		colTileset[i] = (bool*)malloc(levelWidth* sizeof(bool));
	}

	for (int i = 0; i < levelHeight; i++) {
		for (int j = 0; j < levelWidth; j++) {
			//tileset[i][j] = (Tile*)malloc;
			//init all of them to null
			colTileset[i][j] = false;
		}
	}
}
