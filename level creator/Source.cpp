#include <SFML/Graphics.hpp>
#include "../game engine/level_loader.h"

int main ()
{
	sf::RenderWindow window (sf::VideoMode (1920, 1080), "Level Creator v0.0");

	level_loader loader("../game_engine/tex/block.png", "../game_engine/tex/blank.png");

	while (window.isOpen ())
	{
		sf::Event event;
		while (window.pollEvent (event))
		{
			if (event.type == sf::Event::Closed)
				window.close ();
		}

		//...
	}

	return 0;
}