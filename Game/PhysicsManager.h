#pragma once
#ifndef __Physics_Manager__
#define __Physics_Manager__

#include "Player.h"

class PhysicsManager{
public:
	PhysicsManager();
	~PhysicsManager();
	void handlePlayerPhysics(Player p);
private:

};

#endif