#include <SFML/Graphics.hpp>
#include "../game engine/level_loader.h"

#include "wall_object.h"
#include "../SFML_Menu/Menu.h"

int main ()
{
	sf::RenderWindow window (sf::VideoMode (1920, 1080), "Level Creator v0.0");

	level_loader loader("../game_engine/tex/block.png", "../game_engine/tex/blank.png");

	window_manager w_manager;

	wall_object wall (100, 100, 200, 200);

	w_manager.add_window (&wall);

	while (window.isOpen ())
	{
		sf::Event event;
		while (window.pollEvent (event))
		{
			if (event.type == sf::Event::Closed)
				window.close ();

			w_manager.handle_event (event);
			
			if (event.type == sf::Event::MouseMoved)
				w_manager.update_cursor (event.mouseMove, window.getSystemHandle ());
		}
		
		window.clear (sf::Color::White);
		w_manager.draw_windows (window);

		window.display ();
	}

	return 0;
}