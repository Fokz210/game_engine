#pragma once

#include <stdio.h>

#include "test_sprite.h"
#include "test_wall.h"
#include "light_source.h"

#include "../level creator/level_header.h"

class level
{
public:
	using sprites_array = std::vector <sprite_object *>;
	using lights_array = std::vector <light_source *>;
	using walls_array = std::vector <wall_sprite *>;

	level ();

	sprites_array sprites_;
	lights_array lights_;
	walls_array walls_;
};

