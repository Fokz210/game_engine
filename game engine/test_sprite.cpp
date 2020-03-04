#include "test_sprite.h"

sprite_object::sprite_object () :
	drawable_game_object (),
	sprite_ ()
{
}

sprite_object::sprite_object (sf::Sprite sprite)  :
	drawable_game_object (),
	sprite_ (sprite)
{
}

sprite_object::~sprite_object ()
{
}

void sprite_object::draw (sf::RenderTarget& target)
{
	target.draw (sprite_);
}

sf::Drawable& sprite_object::get_drawable ()
{
	return sprite_;
}

void sprite_object::update ()
{
	// NONE
}

sf::Sprite& sprite_object::get_sprite ()
{
	return sprite_;
}

void sprite_object::set_sprite (sf::Sprite& sprite)
{
	sprite_ = sprite;
}

sf::Vector2f sprite_object::get_size () const
{
	return sf::Vector2f (sprite_.getTexture ()->getSize ().x, sprite_.getTexture ()->getSize ().y);
}

sf::Vector2f sprite_object::get_offset () const
{
	return sprite_.getPosition ();
}
