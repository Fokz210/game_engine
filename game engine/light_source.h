#pragma once
#include "game_object.h"

class light_source :
	public game_object
{	
public:
	light_source ();
	light_source (sf::Vector2f position);

	sf::Vector2f get_position () const;
	void set_position (sf::Vector2f position);

protected:
	sf::Vector2f position_;
};

