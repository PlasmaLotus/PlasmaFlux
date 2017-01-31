#ifndef __Game_Renderer__
#define __Game_Renderer__

#include "SFML\Graphics.hpp"

class GameRenderer {
public:
	GameRenderer();
	GameRenderer(sf::RenderWindow &w);
	~GameRenderer();

	void render();
	void clear();
	void draw();
	void display();


private:
	

};

#endif
