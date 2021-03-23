#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

using namespace sf;
using namespace std;

Animation::Animation(Texture texture, int maxRow, int maxCol)
{
	this->texture = texture;
	this->maxRow = maxRow;
	this->maxCol = maxCol;

	Vector2u size = this->texture.getSize();
	
	width = size.x;
	height = size.y;

}

Sprite Animation::animate(float time, Clock clock) 
{
	IntRect rectSourceSprite(0, 0, width / maxCol, height / maxRow);
	Sprite sprite(texture, rectSourceSprite);
	if (clock.getElapsedTime().asSeconds() > time) {
		if (rectSourceSprite.left >= width - (width / maxCol)) {
			rectSourceSprite.left = 0;
		}
		else {
			rectSourceSprite.left += (width / maxCol);
		}

		sprite.setTextureRect(rectSourceSprite);
		time = clock.restart().asSeconds();
	}

	return sprite;
}



