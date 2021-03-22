#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    
	//This makes a window
	RenderWindow window(VideoMode(500, 500), "Test Window", Style::Resize | Style::Close);
	CircleShape rectangle(10.0f);
	rectangle.setFillColor(Color::Red);

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

		if (Keyboard::isKeyPressed(Keyboard::Key::W))
		{
			rectangle.move(0.0f, -0.1f);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::A))
		{
			rectangle.move(-0.1f, 0.0f);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::S))
		{
			rectangle.move(0.0f, 0.1f);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::D))
		{
			rectangle.move(0.1f, 0.0f);
		}
		else if (Mouse::isButtonPressed(Mouse::Left))
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