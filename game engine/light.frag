uniform vec2 bounds[64];
uniform vec2 light;

uniform int bounds_size;

uniform sampler2D current;

uniform vec2 offset;
uniform vec2 resolution;
uniform vec2 tex_size;

bool need_draw();

void main ()
{
    vec4 color = texture2D (current, gl_TexCoord[0].st);

    gl_FragColor = color;
}

