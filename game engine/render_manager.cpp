#include "render_manager.h"

render_manager::render_manager () :
	objects_ (),
	lighing_ (),
	opaques_ (),
	lighting_shader_ (nullptr)
{
}

render_manager::objects_array& render_manager::get_objects_array ()
{
	return objects_;
}

render_manager::lights_array& render_manager::get_lights_array ()
{
	return lighing_;
}

render_manager:: opaques_array& render_manager::get_opaques_array ()
{
	return opaques_;
}

void render_manager::set_shader (sf::Shader * shader)
{
	lighting_shader_ = shader;
}

void render_manager::render (sf::RenderTarget& target)
{
	opaques_
}
