#pragma once
#include "test_sprite.h"
#include "opaque_object.h"

class wall_sprite :
	public sprite_object,
	public opaque_object
{
public:
	wall_sprite ();
	wall_sprite (sf::Sprite sprite);

	virtual sf::FloatRect get_bounds () override;
};

