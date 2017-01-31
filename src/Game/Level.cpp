#include "Level.h"

Level::Level():
levelHeight(0),
levelWidth(0),
initiated(false){
}
Level::~Level(){
	
	if (initiated)
	{
		for (int i = 0; i < levelWidth; i++) {
			for (int j = 0; j < levelHeight; j++) {
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
		}
		free(tileset);
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
							initTileset();

							std::string tileText = text;
							for (int i = 0; i < levelWidth; i++) {
								for (int j = 0; j < levelHeight; j++) {
									if (tileText == "")
									{
										break;
									}

									if (tileText.find("block")!= std::string::npos)
									{
										//tileset[i][j] = new Tile();
										createTile(i, j);
									}
									std::getline(file, tileText);
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

void Level::initTileset()
{
	tileset = (Tile***)malloc(levelHeight* sizeof(Tile**));
	for (int i = 0; i < levelHeight; i++)
	{
		tileset[i] = (Tile**)malloc(levelHeight* sizeof(Tile*));
	}

	for (int i = 0; i < levelWidth; i++) {
		for (int j = 0; j < levelHeight; j++) {
			//tileset[i][j] = (Tile*)malloc;
			//init all of them to null
			tileset[i][j] = NULL;
		}
	}

	initiated = true;
}

void Level::testInit() {
	for (int i = 0; i < levelWidth; i++) {
		for (int j = 0; j < levelHeight; j++) {
			if (tileset[i][j] != NULL)
			{
				//if there is a tile
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
	}
}

void Level::createTile(int x, int y)
{
	tileset[x][y] = new Tile();
}

void Level::clearTile(int x, int y)
{
	if (tileset[x][y] != NULL)
		delete tileset[x][y];
}
