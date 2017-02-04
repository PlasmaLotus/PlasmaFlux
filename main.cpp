/*
PlasmaFlux 
Platformer developpement 
Created by PlasmaLotus
29/01/2017
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML\Graphics.hpp>
#include "main.h"
#include "Game\Level.h"

void test();
int main(int argc, char **argv) {

	Level l;
	l.loadLevel("assets/levels/test.lvl");
	l.initLevel();

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
	sf::RenderWindow lul(sf::VideoMode(240, 160), "PlasmaFlux");
	Game game(lul);
	game.run();


	return 0;
}

void test() {
	for (int i = 0; i < 50000; i++)
	{
		Level levelTest;
		levelTest.loadLevel("assets/levels/test.lvl");
	}
}