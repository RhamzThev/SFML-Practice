#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    
	//This makes a window
	RenderWindow window(VideoMode(500, 500), "Test Window", Style::Resize | Style::Close);
	RectangleShape rectangle(Vector2f(50.0f, 50.0f));

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

			window.draw(rectangle);
		}
	}

	return 0;
}