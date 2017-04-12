#pragma once

#ifndef __MovingPlatform__
#define __MovingPlatform__

class MovingPlatform {
public:
	MovingPlatform();
	MovingPlatform(int pX, int pY, float spdX, float spdY, int pendX, int pendY);
	~MovingPlatform();

	void update();
private:
	double angle;
	float speedX;
	float speedY;
	float posX;
	float posY;
	float sizeX;
	float sizeY;
	float rangeX;
	float rangeY;
};

#endif