#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    
	//This makes a window
	int size = 500;
	RenderWindow window(VideoMode(size, size), "Test Window", Style::Resize | Style::Close);

	float rectangleSize = 500.0f;
	RectangleShape rectangle(Vector2f(rectangleSize, rectangleSize));
	float center = ((float)size / 2.0f) - (rectangleSize / 2.0f);
	rectangle.setPosition(center, center);
	//rectangle.setFillColor(Color::Red);

	Texture texture;
	texture.loadFromFile("C:/Users/coolr/Visual Studio Code/gamedev/SFML Practice/SFML Practice/Textures/checkers.png");
	rectangle.setTexture(&texture);

	Vector2u textureSize = texture.getSize();
	textureSize.x /= 5;
	textureSize.y /= 5;

	rectangle.setTextureRect(IntRect(textureSize.x * 2, textureSize.y * 4, textureSize.x, textureSize.y));

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

		window.clear();
		window.draw(rectangle);
		window.display();
	}

	return 0;
}