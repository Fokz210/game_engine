#pragma once
#include "sprite_game_object.h"

class point_movig_character :
	public sprite_game_object
{
public:
	point_movig_character ();
	point_movig_character (sf::Sprite sprite, float speed = 0.0f);

	void go_to (sf::Vector2f move_target);
	float get_speed ();
	void  set_speed (float speed);

	virtual void update () override;

protected:
	sf::Vector2f move_target_;
	float speed_;
	bool moving_;
};

