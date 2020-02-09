#include <SFML/Graphics.hpp>

#include "render_manager.h"
#include "test_wall.h"

int main ()
{
	sf::RenderWindow window(sf::VideoMode (1920, 1080), "game_engine");

	light_source light;

	sf::Texture wall_texture;
	wall_texture.loadFromFile ("tex/block.png");
	
	sf::Sprite wall_sprite (wall_texture);

	test_wall wall (wall_sprite);
	wall.get_sprite ().setPosition (400, 400);

	test_wall wall2 (wall_sprite);
	wall2.get_sprite ().setPosition (900, 400);

	sf::Texture back_texture;
	back_texture.loadFromFile ("tex/blank.png");

	sf::Sprite back_sprite (back_texture);

	test_sprite back (back_sprite);
	
	render_manager r_manager;
	r_manager.load_shader ("light.frag");

	r_manager.get_lights_array ().push_back (&light);
	r_manager.get_opaques_array ().push_back (&wall);
	r_manager.get_opaques_array ().push_back (&wall2);
	r_manager.get_objects_array ().push_back (&back);
	r_manager.get_objects_array ().push_back (&wall);
	r_manager.get_objects_array ().push_back (&wall2);

	while (window.isOpen ())
	{
		window.clear ();
		sf::Event event;

		while (window.pollEvent (event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseMoved)
				light.set_position (sf::Vector2f (event.mouseMove.x, event.mouseMove.y));
		}

		r_manager.render (window);
		window.display ();
	}

	return 0;
}