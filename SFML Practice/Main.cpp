#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

using namespace sf;
using namespace std;

int main() {
    
	//This makes a window
	int size = 1000;
	RenderWindow window(VideoMode(size, size), "Test Window", Style::Resize | Style::Close);

	float rectangleX = 700.0f;
	float rectangleY = 700.0f;
	RectangleShape rectangle(Vector2f(rectangleX, rectangleY));
	float centerX = ((float)size / 2.0f) - (rectangleX / 2.0f);
	float centerY = ((float)size / 2.0f) - (rectangleX / 2.0f);
	rectangle.setPosition(centerX, centerY);
	//rectangle.setFillColor(Color::Red);

	Texture texture;
	texture.loadFromFile("C:/Users/coolr/Visual Studio Code/gamedev/SFML Practice/SFML Practice/Textures/checkers.png");
	rectangle.setTexture(&texture);


	Animation animation(&texture, Vector2u(9, 3), 0.3f);

	float deltaTime = 0.0f;
	Clock clock;

	//This makes a while loop to keep open.
	while (window.isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();
		Event e;

		while (window.pollEvent(e)) 
		{
			
			switch (e.type) 
			{
			case Event::Closed:
				//Closes window
				cout << "Goodbye!" << endl;
				window.close();
				break;
			//case Event::Resized:
			//	//Gives us the size of resized window
			//	cout << "New window width: " << e.size.width << " New window height: " << e.size.height << endl;
			//	break;
			//case Event::TextEntered:
			//	//returns entered text into the terminal
			//	if (e.text.unicode < 128) 
			//	{
			//		printf("%c", e.text.unicode);
			//	}
			}
		}

		/*if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))
		{
			rectangle.move(0.0f, -0.1f);
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			rectangle.move(-0.1f, 0.0f);
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down))
		{
			rectangle.move(0.0f, 0.1f);
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			rectangle.move(0.1f, 0.0f);
		}
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Vector2i mouse = Mouse::getPosition(window);
			rectangle.setPosition((float)(mouse.x), (float)(mouse.y));
		}*/

		animation.update(2, 4, deltaTime);
		rectangle.setTextureRect(animation.uvRect);

		window.clear();
		window.draw(rectangle);
		window.display();
	}

	return 0;
}