#pragma once
#include "drawable_game_object.h"

class sprite_object :
	public drawable_game_object
{
public:
	sprite_object ();
	sprite_object (sf::Sprite sprite);
	~sprite_object () override;

	virtual void draw (sf::RenderTarget & target) override;
	virtual sf::Drawable& get_drawable () override;
	virtual void update () override;

	sf::Sprite& get_sprite ();
	void set_sprite (sf::Sprite& sprite);

	virtual sf::Vector2f get_size () const override;
	virtual sf::Vector2f get_offset () const override;

protected:
	sf::Sprite sprite_;
};

