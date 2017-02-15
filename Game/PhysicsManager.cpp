#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}


void PhysicsManager::handlePlayerPhysics(Player &p, Level &lvl){
 	
	Vec *pPos = p.getPrevPos();
	Vec *nPos = p.getNextPos();

	Bounds nBounds = p.getNextBounds();
	Bounds pBounds = p.getPrevBounds();
	int bboxX = p.getBBoxSizeX();
	int bboxY = p.getBBoxSizeY();

	float tempX = nPos->x;
	float tempY = nPos->y;
	//getBBoxSize
	
	/*For X Axis*/

	if (tempX < 0)
	{
		tempX = 0;
	}
	if (tempX > lvl.levelWidth*TILESIZE)
	{
		tempX = lvl.levelWidth*TILESIZE;
	}
	if (tempY < 0)
	{
		tempY = 0;
	}
	if (tempY > lvl.levelHeight*TILESIZE)
	{
		tempY = lvl.levelHeight*TILESIZE;
	}

	if (nPos->x - pPos->x > 0)//if X change is Positif, if going right
	{
		for (int i = pBounds.right / TILESIZE; i <= nBounds.right / TILESIZE; i++)
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
			if (lvl.getColTile(i, pBounds.up / TILESIZE)) {

				//p.setPosition(i * TILESIZE - 1, nPos->y);
				tempX = i * TILESIZE - bboxX;

				break;
			}
		}
	}
	else if (nPos->x - pPos->x < 0)//if X change is Positif, if going Left
	{
		for (int i = pBounds.left / TILESIZE; i >= nBounds.left / TILESIZE; i--)
		{

			if (lvl.getColTile(i, pBounds.up / TILESIZE)) {

				//p.setPosition(i * TILESIZE , nPos->y);
				tempX = (i+1) * TILESIZE;
				//p.movePosition()

				break;
			}
		}
	}
	
	/*For Y AXIS*/
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
				//p.setPosition(nPos->x, i * TILESIZE - bboxY);
				tempY = i* TILESIZE - bboxY;
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
				//p.setPosition(nPos->x, i * TILESIZE + (TILESIZE));//maybe Tilesize+1
				tempY = i*TILESIZE + (TILESIZE);
				
				break;
			}
		}
	}


	if (tempX < 0)
	{
		tempX = 0;
	}
	if (tempX > lvl.levelWidth*TILESIZE)
	{
		tempX = lvl.levelWidth*TILESIZE;
	}
	if (tempY < 0)
	{
		tempY = 0;
	}
	if (tempY > lvl.levelHeight*TILESIZE)
	{
		tempY = lvl.levelHeight*TILESIZE;
	}
	p.setPosition(tempX, tempY);
	p.tick();

	/*XAxis collision plz*/
}