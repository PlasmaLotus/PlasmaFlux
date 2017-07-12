#pragma once
#ifndef __Physics_Manager__
#define __Physics_Manager__

#include "Player.h"
#include "Level.h"
#include "Tile.h"

class PhysicsManager{
public:
	PhysicsManager();
	~PhysicsManager();
	void _handlePlayerPhysics(Player & p, Level & lvl);
	//void __handlePlayerPhysics(Player & p, Level & lvl);
	void handlePlayerPhysics(Player &p, Level &lvl);
private:
	Level * lvl;
	const int TILESIZE = 16;
	int tic = 0;
};

#endif