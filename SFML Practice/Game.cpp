#include "Game.h"

//Private Funcs

void Game::iVariables()
{
	this->window = nullptr;
}

void Game::iWindow()
{
	this->videoMode.width = 500;
	this->videoMode.height = 500;
	this->window = new RenderWindow(videoMode, "Test Window");
}

//Public Consts and Dests

Game::Game()
{
	this->iVariables();
	this->iWindow();
}

Game::~Game()
{
	delete window;
}

//Public Funcs

void Game::update()
{
	while (window->pollEvent(e))
	{
		switch (e.type)
		{
		case Event::Closed:
			window->close();
			break;
		}
	}
}

void Game::render()
{
	window->clear();
	window->display();
}

const bool Game::running() const
{
	return window->isOpen();
}

