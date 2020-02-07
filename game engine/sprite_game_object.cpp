#include "sprite_game_object.h"

sprite_game_object::sprite_game_object () 
	: drawable_game_object(),
	sprite_ ()
{
}

sprite_game_object::sprite_game_object (sf::Sprite sprite)
	: drawable_game_object (),
	sprite_ (sprite)
{
}

sf::Sprite& sprite_game_object::get_sprite ()
{
	return sprite_;
}

void sprite_game_object::set_sprite (sf::Sprite& sprite)
{
	sprite_ = sprite;
}

void sprite_game_object::draw (sf::RenderTarget& target)
{
	target.draw (sprite_);
}

void sprite_game_object::update ()
{
	//none
}
