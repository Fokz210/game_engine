#include "render_manager.h"

render_manager::render_manager () :
	level_ (),
	lighting_shader_ (nullptr),
	loaded_ (false)
{
}

render_manager::~render_manager ()
{
	if (loaded_ && lighting_shader_)
		delete lighting_shader_;
}

void render_manager::set_shader (sf::Shader * shader)
{
	lighting_shader_ = shader;
}

void render_manager::load_shader (std::string shader_path)
{
	loaded_ = true;

	lighting_shader_ = new sf::Shader ();
	lighting_shader_->loadFromFile (shader_path, sf::Shader::Type::Fragment);
}

void render_manager::render (sf::RenderTarget& target)
{
	static int frame = 0;
	frame++;

	const int bounds_size = 64;

	sf::Glsl::Vec2 bounds[bounds_size] = {};

	for (int i = 0; i < level_.walls_.size (); i++)
	{
		sf::FloatRect rect = level_.walls_[i]->get_bounds ();

		bounds[i * 4] = sf::Glsl::Vec2 (rect.left, rect.top);
		bounds[i * 4 + 1] = sf::Glsl::Vec2 (rect.left + rect.width, rect.top);
		bounds[i * 4 + 2] = sf::Glsl::Vec2 (rect.left + rect.width, rect.top + rect.height);
		bounds[i * 4 + 3] = sf::Glsl::Vec2 (rect.left, rect.top + rect.height);
	};

	lighting_shader_->setUniformArray ("bounds", bounds, bounds_size);
	lighting_shader_->setUniform ("light", sf::Glsl::Vec3 (level_.lights_[0]->get_position().x, level_.lights_[0]->get_position().y, level_.lights_[0]->get_radius()));

	lighting_shader_->setUniform ("bounds_size", int (level_.walls_.size()));

	lighting_shader_->setUniform ("current", sf::Shader::CurrentTexture);

	lighting_shader_->setUniform ("frame", float (frame));

	for (auto&& el : level_.sprites_)
	{
		lighting_shader_->setUniform ("normal", el->get_normal ());
		lighting_shader_->setUniform ("use_normal", true);
		lighting_shader_->setUniform ("offset", el->get_offset ());
		lighting_shader_->setUniform ("tex_size", el->get_size ());
		target.draw (el->get_drawable (), lighting_shader_);
	}

	for (auto && el : level_.walls_)
	{
		lighting_shader_->setUniform ("use_normal", false);
		lighting_shader_->setUniform ("offset", el->get_offset ());
		lighting_shader_->setUniform ("tex_size", el->get_size ());
		target.draw (el->get_drawable (), lighting_shader_);
	}
}