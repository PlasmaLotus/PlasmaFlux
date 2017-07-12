/*
PlasmaFlux 
Platformer developpement 
Created by PlasmaLotus
29/01/2017
*/


#include <SFML\Graphics.hpp>
#include "main.h"
#include "Game\Level.h"
#include "Game\Game.h"
#include "Renderer\GameRenderer.h"
#include "States\StateManager.h"

void test();
int main(int argc, char **argv) {

	//Level l;
	//l.loadLevel("assets/levels/test.lvl");
	//l.initLevel();
	//test();
	/*
	//sf::RenderWindow window;
	sf::Window window(sf::VideoMode(240, 160), "My window");

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	*/

	StateManager& stMng = StateManager::getInstance();
	stMng.run();

	return 0;
}

void test() {
	Level level;
	level.loadLevel("assets/levels/test.lvl");
	/*
	for (int i = 0; i < 50000; i++)
	{
		Level levelTest;
		levelTest.loadLevel("assets/levels/test.lvl");
	}
	*/
}

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
