#pragma once
#include "drawable_game_object.h"


class sprite_game_object :
	public drawable_game_object
{
public:
	sprite_game_object ();
	sprite_game_object (sf::Sprite sprite);
	~sprite_game_object () {};

	sf::Sprite& get_sprite ();
	void		set_sprite (sf::Sprite& sprite);

	virtual void draw (sf::RenderTarget& target) override;
	virtual void update () override;
	virtual sf::Drawable& get_drawable () override;

	virtual sf::Vector2f get_size () const override;
	virtual sf::Vector2f get_offset () const override;

protected:
	sf::Sprite sprite_;
};

