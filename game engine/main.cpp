#include <SFML/Graphics.hpp>

#include "render_manager.h"
#include "test_wall.h"

#include "level_loader.h"

int main ()
{
	sf::RenderWindow window(sf::VideoMode (1920, 1080), "game_engine");

	window.setFramerateLimit (60);
	
	render_manager r_manager;
	r_manager.load_shader ("light.frag");

	level_loader loader ("tex/block.png", "tex/blank.png");

	loader.load_from_file (r_manager.level_, "level.bin");

	while (window.isOpen ())
	{
		window.clear ();
		sf::Event event;

		while (window.pollEvent (event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseMoved)
				r_manager.level_.lights_[0]->set_position (sf::Vector2f (event.mouseMove.x, event.mouseMove.y));
		}

		r_manager.render (window);
		window.display ();
	}

	return 0;
}