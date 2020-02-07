#pragma once
#include <vector>

#include "drawable_game_object.h"
#include "light_source.h"
#include "opaque_object.h"

class render_manager
{
public:
	using objects_array = std::vector <drawable_game_object*>;
	using lights_array = std::vector <light_source*>;
	using opaques_array = std::vector <opaque_object*>;

	render_manager ();

	objects_array& get_objects_array ();
	lights_array& get_lights_array ();
	opaques_array& get_opaques_array ();

	void set_shader (sf::Shader * shader);

	void render (sf::RenderTarget& target);

protected:
	objects_array objects_;
	lights_array lighing_;
	opaques_array opaques_;

	sf::Shader * lighting_shader_;
};
