#pragma once

#include <cstdio>

#include "level.h"
#include "../level creator/level_header.h"

class level_loader
{
public:
	enum object_type
	{
		undefined,
		sprite,
		light,
		wall
	};

	struct object_info
	{
		int type;
		float x, y;
		float width, height;
	};

	struct level_file_header
	{
		int id;
		int ver;
		int size;
	};

	level_loader (std::string wall_path, std::string sprite_path);
	~level_loader ();

	void save_to_file (level & source, std::string dest) const;
	void load_from_file (level & dest, std::string source);

protected:
	sf::Texture wall_texture_, sprite_texture_;

	level::lights_array loaded_lights_;
	level::sprites_array loaded_sprites_;
	level::walls_array loaded_walls_;
};

