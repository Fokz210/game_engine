#include <SFML/Graphics.hpp>

#include "render_manager.h"
#include "test_wall.h"

int main ()
{
	sf::RenderWindow window(sf::VideoMode (1920, 1080), "game_engine");

	light_source light;
	sf::Texture wall_texture;
	wall_texture.create (1920, 1080);

	render_manager r_manager;
	r_manager.load_shader ("light.glsl");

	while (window.isOpen ())
	{
		sf::Event event;

		while (window.pollEvent (event))
		{
			if (event.type == sf::Event::Closed)
				window.close;
		}

		r_manager.render (window);
		window.display ();
	}

	return 0;
}