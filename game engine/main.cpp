#include <iostream>
#include <SFML/Graphics.hpp>

#include "render_manager.h"
#include "test_wall.h"

#include "level_loader.h"

#include "../SFML_Menu/Menu.h"

int main ()
{
	sf::RenderWindow window (sf::VideoMode (1920, 1080), "game_engine");
	window.setFramerateLimit (60);

	sf::Font font;
	font.loadFromFile ("font.ttf");

	window_manager manager;

	rectangular_window rwnd (100, 100, 150, 50, sf::Color::Red);
	rectangular_window bwnd (100, 500, 150, 50, sf::Color::Blue);
	
	auto lambda = []() 
	{
		std::cout << "Pressed!" << std::endl;
	};

	text_button <decltype (lambda)> btn (600.f, 20.f, 150.f, 50.f, sf::Color::Green, sf::Color::Black, "button", font, lambda);

	manager.add_window (&rwnd);
	manager.add_window (&bwnd);
	manager.add_window (&btn);

	while (window.isOpen ())
	{
		window.clear ();

		sf::Event event;

		while (window.pollEvent (event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close ();
				break;
			}

			if (event.type == sf::Event::MouseMoved)
				manager.update_cursor (event.mouseMove, window.getSystemHandle ());

			if (manager.handle_event (event))
				break;
		}

		manager.draw_windows (window);
		window.display ();
	}
}

int mmain ()
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