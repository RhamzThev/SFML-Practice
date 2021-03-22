#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    
	//This makes a window
	RenderWindow window(VideoMode(500, 500), "Test Window", Style::Resize | Style::Close);

	CircleShape rectangle(10.0f);
	//rectangle.setFillColor(Color::Red);

	Texture texture;
	texture.loadFromFile("C:/Users/coolr/Visual Studio Code/gamedev/SFML Practice/SFML Practice/Textures/micro_logo.png");
	rectangle.setTexture(&texture);

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
			case Event::Resized:
				//Gives us the size of resized window
				cout << "New window width: " << e.size.width << " New window height: " << e.size.height << endl;
				break;
			case Event::TextEntered:
				//returns entered text into the terminal
				if (e.text.unicode < 128) 
				{
					printf("%c", e.text.unicode);
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))
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
		}

		window.clear();
		window.draw(rectangle);
		window.display();
	}

	return 0;
}