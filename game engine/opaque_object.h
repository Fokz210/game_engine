#pragma once
#include "game_object.h"


class opaque_object :
	public game_object
{
public:
	opaque_object ();

	virtual sf::FloatRect get_bounds () = 0;
};

