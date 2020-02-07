#pragma once
#include "drawable_game_object.h"


class sprite_game_object :
	public drawable_game_object
{
public:
	sprite_game_object ();
	sprite_game_object (sf::Sprite sprite);

	sf::Sprite& get_sprite ();
	void		set_sprite (sf::Sprite& sprite);

	virtual void draw (sf::RenderTarget& target) override;
	virtual void update () override;

protected:
	sf::Sprite sprite_;
};

