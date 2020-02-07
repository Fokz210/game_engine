#pragma once
#include "game_object.h"

class drawable_game_object :
	public game_object
{
public:
	drawable_game_object ();
	virtual ~drawable_game_object () = 0;

	virtual void draw (sf::RenderTarget& target) = 0;
	virtual sf::Drawable& get_drawable () = 0;
	virtual void update () = 0;
};

