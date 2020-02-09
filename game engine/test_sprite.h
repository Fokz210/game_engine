#pragma once
#include "drawable_game_object.h"

class test_sprite :
	public drawable_game_object
{
public:
	test_sprite ();
	test_sprite (sf::Sprite sprite);

	virtual void draw (sf::RenderTarget & target) override;
	virtual sf::Drawable& get_drawable () override;
	virtual void update () override;

	sf::Sprite& get_sprite ();
	void set_sprite (sf::Sprite& sprite);

protected:
	sf::Sprite sprite_;
};

