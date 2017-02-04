
#ifndef __Level__
#define __Level__

#include <fstream>
#include <string.h>
#include <string>
#include "Tile.h"


class Level {
public:

	Level();
	~Level();

	unsigned int levelHeight;
	unsigned int levelWidth;
	static const int TILESIZEX = 16;
	static const int TILESIZEY = 16;

	//bool loadLevel();
	bool loadLevel(std::string levelName);
	bool initLevel();
	Tile *getTile(int x, int y);
	bool getColTile(int x, int y);
	bool **getCollisionTiles();

	

	enum levelAttributes { Dimensions, ScrollLock, AutoScroll, Tiles };
private:

	struct TileInfo{
		Tile tile;
		//spawnpoint
	};
	bool initiated;
	void initColTileset();
	void initTileset();
	void createTile(int width, int height);
	void clearTile(int x, int y);
	void testInit();

	Tile ***tileset;
	bool **colTileset;
	
};
#endif