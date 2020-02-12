#pragma once
#include "game_object.h"

class light_source :
	public game_object
{	
public:
	light_source ();
	light_source (sf::Vector2f position, float radius = 0.0f);

	sf::Vector2f get_position () const;
	void set_position (sf::Vector2f position);
	
	float get_radius () const;
	void set_radius (float radius);

protected:
	sf::Vector2f position_;
	float radius_;
};

