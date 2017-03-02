#pragma once

#ifndef __Enemy__
#define __Enemy__

class Enemy {
public:
	Enemy();
	~Enemy();

private:
	float prevPosX;
	float prevPosY;
	float nextPosX;
	float nextPosY;
};

#endif