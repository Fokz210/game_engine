#include "character.h"

character::character ()
	: sprite_game_object (),
	  move_target_ (),
	  speed_ (),
	  moving_ ()
{
}

character::character (sf::Sprite sprite, float speed) 
	: sprite_game_object (sprite),
	  move_target_ (),
	  speed_ (speed),
	  moving_ ()
{
}

void character::go_to (sf::Vector2f move_target)
{
	move_target_ = move_target;
	moving_ = true;
}

float character::get_speed ()
{
	return speed_;
}

void character::set_speed (float speed)
{
	speed_ = speed;
}

void character::update ()
{
	// todo: create moving function
}
