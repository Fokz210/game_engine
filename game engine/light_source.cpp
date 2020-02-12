#include "light_source.h"

light_source::light_source () :
	position_(),
	radius_ ()
{
}

light_source::light_source (sf::Vector2f position, float radius) :
	position_ (position),
	radius_ (radius)
{
}

sf::Vector2f light_source::get_position () const
{
	return position_;
}

void light_source::set_position (sf::Vector2f position)
{
	position_ = position;
}

float light_source::get_radius () const
{
	return radius_;
}

void light_source::set_radius (float radius)
{
	radius_ = radius;
}
