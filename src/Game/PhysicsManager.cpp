#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}


void PhysicsManager::handlePlayerPhysics(Player p){
	p.tick();
	Vec *nPos = p.getNextPos();

}