#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Game
{

private:
	//variables
	RenderWindow *window;
	Event e;
	VideoMode videoMode;

	//Funcs
	void iVariables();
	void iWindow();

public:
	//Consts and Dests
	Game();
	~Game();

	//Funcs
	void update();
	void render();

	//Gets and Sets
	const bool running() const;
};

