#include "test_sprite.h"

test_sprite::test_sprite () :
	drawable_game_object (),
	sprite_ ()
{
}

test_sprite::test_sprite (sf::Sprite sprite)  :
	drawable_game_object (),
	sprite_ (sprite)
{
}

test_sprite::~test_sprite ()
{
}

void test_sprite::draw (sf::RenderTarget& target)
{
	target.draw (sprite_);
}

sf::Drawable& test_sprite::get_drawable ()
{
	return sprite_;
}

void test_sprite::update ()
{
	// NONE
}

sf::Sprite& test_sprite::get_sprite ()
{
	return sprite_;
}

void test_sprite::set_sprite (sf::Sprite& sprite)
{
	sprite_ = sprite;
}

sf::Vector2f test_sprite::get_size () const
{
	return sf::Vector2f (sprite_.getTexture ()->getSize ().x, sprite_.getTexture ()->getSize ().y);
}

sf::Vector2f test_sprite::get_offset () const
{
	return sprite_.getPosition ();
}
