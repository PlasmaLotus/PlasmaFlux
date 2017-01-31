
#ifndef __Level__
#define __Level__

#include <fstream>
#include <string.h>
#include "Tile.h"


class Level {
public:

	Level();
	~Level();



	//bool loadLevel();
	bool loadLevel(std::string levelName);
	bool initLevel();

	enum levelAttributes { Dimensions, ScrollLock, AutoScroll, Tiles };
private:

	struct TileInfo{
		Tile tile;
		//spawnpoint
	};
	bool initiated;
	unsigned int levelHeight;
	unsigned int levelWidth;
	static const int TILESIZEX = 16;
	static const int TILESIZEY = 16;
	void initTileset();
	void createTile(int width, int height);
	void clearTile(int x, int y);
	void testInit();

	Tile ***tileset;
	
};
#endif