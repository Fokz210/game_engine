#pragma once
#include "test_sprite.h"
#include "opaque_object.h"

class test_wall :
	public test_sprite,
	public opaque_object
{
public:
	test_wall ();
	test_wall (sf::Sprite sprite);

	virtual sf::FloatRect get_bounds () override;
};

