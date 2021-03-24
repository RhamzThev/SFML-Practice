#include "Game.h"
#include <iostream>

using namespace sf;
using namespace std;

int main() {

	//This makes a Game
	Game game;

	//This makes a while loop to keep open.
	while (game.running()) 
	{
		//update
		game.update();
		//render
		game.render();
	}

	return 0;
}