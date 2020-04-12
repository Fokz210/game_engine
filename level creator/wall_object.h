#pragma once
#include "..\SFML_Menu\rectangular_window.h"

class wall_object :
	public rectangular_window
{
public:
	wall_object (float x, float y, float width, float height);

	virtual bool mouse_button_pressed (sf::Event::MouseButtonEvent event) override;
	virtual bool global_mouse_button_released (sf::Event::MouseButtonEvent event) override;
	virtual bool mouse_move (sf::Event::MouseMoveEvent event) override;

protected:
	sf::Vector2f offset_;
	bool lock_pos_;
	bool lock_size_x;
	bool lock_size_y;
};

