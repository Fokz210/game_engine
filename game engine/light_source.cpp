#include "light_source.h"

light_source::light_source () :
	position_()
{
}

light_source::light_source (sf::Vector2f position) :
	position_ (position)
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
