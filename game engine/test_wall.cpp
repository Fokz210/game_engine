#include "test_wall.h"

wall_sprite::wall_sprite () :
	sprite_object (),
	opaque_object ()
{
}

wall_sprite::wall_sprite (sf::Sprite sprite) :
	sprite_object (sprite),
	opaque_object ()
{
}

sf::FloatRect wall_sprite::get_bounds ()
{
	return sprite_.getGlobalBounds();
}
