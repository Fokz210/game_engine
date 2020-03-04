#pragma once
#include <vector>

#include "drawable_game_object.h"
#include "light_source.h"
#include "opaque_object.h"

#include "level.h"

class render_manager
{
public:
	render_manager ();
	~render_manager ();

	void set_shader (sf::Shader * shader);
	void load_shader (std::string shader_path);

	void render (sf::RenderTarget& target);

	level level_;
protected:
	
	sf::Shader * lighting_shader_;
	bool loaded_;
};
