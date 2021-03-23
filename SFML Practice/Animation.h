#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Animation
{
public: 
	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	void update(int row, float deltaTime);
	void update(int row, int col, float deltaTime);

	IntRect uvRect;


private:
	Vector2u imageCount;
	Vector2u currentImage;

	float totalTime;
	float switchTime;



};

