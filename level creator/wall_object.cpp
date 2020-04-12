#include "wall_object.h"

wall_object::wall_object (float x, float y, float width, float height) :
	rectangular_window (x, y, width, height, sf::Color::Black),
	offset_ (),
	lock_pos_ (false),
	lock_size_x (false),
	lock_size_y (false)
{
}

bool wall_object::mouse_button_pressed (sf::Event::MouseButtonEvent event)
{
	offset_ = sf::Vector2f (event.x - shape_.getPosition ().x, event.y - shape_.getPosition ().y);

	if (event.x > shape_.getGlobalBounds ().left + shape_.getGlobalBounds ().width - 20)
	{
		lock_size_x = true;
		offset_.x -= shape_.getSize ().x;
	}

	if (event.y > shape_.getGlobalBounds ().top + shape_.getGlobalBounds ().height - 20)
	{
		lock_size_y = true;
		offset_.y -= shape_.getSize ().y;
	}
	
	if (!lock_size_x && !lock_size_y)
		lock_pos_ = true;

	return true;
}

bool wall_object::global_mouse_button_released (sf::Event::MouseButtonEvent event)
{
	offset_ = sf::Vector2f ();
	lock_pos_ = false;
	lock_size_x = false;
	lock_size_y = false;

	return false;
}

bool wall_object::mouse_move (sf::Event::MouseMoveEvent event)
{
	if (lock_pos_)
		shape_.setPosition(event.x - offset_.x, event.y - offset_.y);

	if (lock_size_x)
	{
		shape_.setSize (sf::Vector2f(event.x - offset_.x - shape_.getPosition ().x, shape_.getSize().y));
	}

	if (lock_size_y)
	{
		shape_.setSize (sf::Vector2f(shape_.getSize ().x, event.y - offset_.y - shape_.getPosition ().y));
	}

	return true;
}
