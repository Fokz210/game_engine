#include "test_wall.h"

test_wall::test_wall () :
	test_sprite (),
	opaque_object ()
{
}

test_wall::test_wall (sf::Sprite sprite) :
	test_sprite (sprite),
	opaque_object ()
{
}

sf::FloatRect test_wall::get_bounds ()
{
	return sprite_.getGlobalBounds();
}
