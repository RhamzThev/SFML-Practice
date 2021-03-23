#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

using namespace sf;
using namespace std;

int main() {
    
	Texture texture;
	texture.loadFromFile("C:/Users/coolr/Visual Studio Code/gamedev/SFML Practice/SFML Practice/Textures/hello.png");

	//This makes a window
	Vector2u size = texture.getSize();
	int width = size.x;
	int height = size.y;

	int rows = 1;
	int cols = 6;

	float deltaTime = 0.0f;
	Clock clock;

	Animation animation = Animation::Animation(texture, rows, cols);

	RenderWindow window(VideoMode(width / cols, height), "Test Window");

	//This makes a while loop to keep open.
	while (window.isOpen()) 
	{
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
			}
		}

		Sprite sprite = animation.animate(0.5f, clock);

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}

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