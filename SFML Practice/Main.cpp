#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {

	//This makes a window
	Vector2u size(500, 500);
	int width = size.x;
	int height = size.y;

	RenderWindow window(VideoMode(width, height), "Test Window");
	Event e;

	//This makes a while loop to keep open.
	while (window.isOpen()) 
	{
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

		//displays le window
		window.clear(Color::White);
		window.display();
	}

	return 0;
}