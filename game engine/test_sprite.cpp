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

