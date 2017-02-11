#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}


void PhysicsManager::handlePlayerPhysics(Player &p, Level &lvl){
	p.tick();
	float prevYPos = p.getPrevYPos();
	Vec *pPos = p.getPrevPos();
	Vec *nPos = p.getNextPos();

	Bounds nBounds = p.getNextBounds();
	Bounds pBounds = p.getPrevBounds();
	int bboxX = p.getBBoxSizeX();
	int bboxY = p.getBBoxSizeY();
	//getBBoxSize
	//For Y AXIS
	if (nPos->y - pPos->y > 0)//if Y change is Positif, if going down
	{
		for (int i = pBounds.down / TILESIZE; i <= nBounds.down / TILESIZE; i++)
		{
			/*
			int  okX = p.getPrevXPos() / TILESIZE;
			if (okX >= 2){
				okX = 2;
			}
			if (nPos->y / TILESIZE >= 14){
				int debut = nPos->x;
			}
			*/
			if (lvl.getColTile(pBounds.right/TILESIZE, i)) {
				//accomodate pos
				p.setPosition(p.getNextXPos(), i * TILESIZE - bboxY);
				//p.setYSpeed(0.0);
				p.isOnGround(true);
				break;
			}
		}
	}
	else if (nPos->y - pPos->y < 0)//if Y change is Negative, if going up
	{
		for (int i = pBounds.up / TILESIZE; i >= nBounds.up/ TILESIZE; i--)
		{

			if (lvl.getColTile(pBounds.right / TILESIZE, i)) {
				//accomodate pos
				p.setPosition(p.getNextXPos(), i * TILESIZE + (TILESIZE));//maybe Tilesize+1
				//p.setYSpeed(0.0);
				break;
			}
		}
	}

	
}