#include "level_loader.h"
#include <stdexcept>

level_loader::level_loader (std::string wall_path, std::string sprite_path) :
	wall_texture_ (),
	sprite_texture_ ()
{
	sf::Image sprite_image;
	sprite_image.loadFromFile (sprite_path);

	sprite_texture_.loadFromImage (sprite_image);

	sf::Image wall_image;
	wall_image.loadFromFile (wall_path);

	wall_texture_.loadFromImage (wall_image);

	sprite_texture_.setRepeated (true);
	wall_texture_.setRepeated (true);
}

level_loader::~level_loader ()
{
	for (auto && el : loaded_lights_)
		if (el)
			delete el;

	for (auto && el : loaded_sprites_)
		if (el)
			delete el;

	for (auto && el : loaded_walls_)
		if (el)
			delete el;
}

void level_loader::save_to_file (level & dest, std::string source) const
{
	level_file_header header;

	header.id = CREATOR_ID;
	header.ver = CREATOR_VERSION;
	
	int size = dest.sprites_.size () + dest.lights_.size () + dest.walls_.size();

	header.size = size;

	object_info * info = new object_info[size];

	for (int i = 0; i < size; i++)
		info[i] = {};

	for (int i = 0; i < dest.sprites_.size (); i++)
	{
		info[i].type = object_type::sprite;
		info[i].x = dest.sprites_[i]->get_offset ().x;
		info[i].y = dest.sprites_[i]->get_offset ().y;
		info[i].width = dest.sprites_[i]->get_size ().x;
		info[i].height = dest.sprites_[i]->get_size ().y;
	}

	for (int i = dest.sprites_.size (); i < dest.sprites_.size () + dest.lights_.size (); i++)
	{
		info[i].type = object_type::light;
		info[i].x = dest.lights_[i - dest.sprites_.size ()]->get_position ().x;
		info[i].y = dest.lights_[i - dest.sprites_.size ()]->get_position ().x;
		info[i].width = dest.lights_[i - dest.sprites_.size ()]->get_radius();
		info[i].height = 0.f;
	}

	for (int i = dest.sprites_.size () + dest.lights_.size (); i < size; i++)
	{
		info[i].type = object_type::wall;
		info[i].x = dest.walls_[i - dest.sprites_.size () - dest.lights_.size ()]->get_bounds ().left;
		info[i].y = dest.walls_[i - dest.sprites_.size () - dest.lights_.size ()]->get_bounds ().top;
		info[i].width = dest.walls_[i - dest.sprites_.size () - dest.lights_.size ()]->get_bounds ().width;
		info[i].height = dest.walls_[i - dest.sprites_.size () - dest.lights_.size ()]->get_bounds ().height;
	}

	FILE * file;
	fopen_s (&file, source.c_str (), "wb");

	if (!file)
		throw std::exception ("failed to open file");

	fwrite (&header, sizeof (header), 1, file);
	fwrite (info, sizeof (object_info), size, file);

	fclose (file);
}

void level_loader::load_from_file (level & dest, std::string source)
{
	level_file_header header;

	FILE * file;
	fopen_s (&file, source.c_str (), "rb");

	if (!file)
		throw std::exception ("failed to open file");

	fread (&header, sizeof (header), 1, file);

	if (header.id != CREATOR_ID)
		throw std::exception ("Level creator id is wrong. Maybe file corruption or error while reading.");

	if (header.ver != CREATOR_VERSION)
		throw std::exception ("Old version of level file. May be errors with sync.");

	object_info * info = new object_info[header.size];
	for (int i = 0; i < header.size; i++)
		info[i] = {};

	fread (info, sizeof (object_info), header.size, file);
	fclose (file);

	for (int i = 0; i < header.size; i++)
	{
		switch (info[i].type)
		{
		case object_type::undefined:
			break;

		case object_type::sprite:
		{
			sf::Sprite sprite (sprite_texture_);
			sprite.setPosition (info[i].x, info[i].y);
			sprite.setTextureRect (sf::IntRect (0, 0, info[i].width, info[i].height));
			
			sprite_object * object = new sprite_object (sprite);

			loaded_sprites_.push_back (object);
			dest.sprites_.push_back (object);
		}
		break;

		case object_type::light:
		{
			light_source * source = new light_source (sf::Vector2f (info[i].x, info[i].y), info[i].width);
			
			loaded_lights_.push_back (source);
			dest.lights_.push_back (source);
		}
		break;

		case object_type::wall:
		{
			sf::Sprite sprite (wall_texture_);
			sprite.setPosition (info[i].x, info[i].y);
			sprite.setTextureRect (sf::IntRect (0, 0, info[i].width, info[i].height));

			wall_sprite * wall = new wall_sprite (sprite);

			loaded_walls_.push_back (wall);
			dest.walls_.push_back (wall);
		}
		break;
		

		default:
			break;
		}
	}

	delete[] info;
}