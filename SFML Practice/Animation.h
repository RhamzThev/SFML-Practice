#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Animation
{
public:
	Animation(Texture texture, int maxRow, int maxCol);
	Sprite animate(float time, Clock clock);

private:
	Texture texture;

	int maxRow;
	int maxCol;

	int width;
	int height;

};

