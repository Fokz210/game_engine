uniform vec2 bounds[64];
uniform vec2 light;

uniform int bounds_size;

uniform sampler2D current;

uniform vec2 offset;
uniform vec2 tex_size;

bool need_draw();
bool intersect_1 (float a, float b, float c, float d);
float area (vec2 a, vec2 b, vec2 c);
bool intersect (vec2 a, vec2 b, vec2 c, vec2 d);

void main ()
{
    vec4 color = texture2D (current, gl_TexCoord[0].st);

    if (!need_draw())
        color.xyz = vec3(0.1, 0.1, 0.1);

    gl_FragColor = color;
}

bool need_draw ()
{
    vec2 curr_pos = gl_TexCoord[0].st;
    vec2 global_pos = vec2 (offset.x + curr_pos.x * tex_size.x, offset.y + curr_pos.y * tex_size.y);

    for (int i = 0; i < bounds_size; i++)
    {
        if (intersect (global_pos, light, bounds[i * 4], bounds[i * 4 + 1]) ||
            intersect (global_pos, light, bounds[i * 4 + 1], bounds [i * 4 + 2]) ||
            intersect (global_pos, light, bounds[i * 4 + 2], bounds [i * 4 + 3]) ||
            intersect (global_pos, light, bounds[i * 4 + 3], bounds [i * 4]))
            return false;
    }

    return true;
}

bool intersect (vec2 a, vec2 b, vec2 c, vec2 d)
{
    return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0.0
		&& area(c,d,a) * area(c,d,b) <= 0.0;
}

bool intersect_1 (float a, float b, float c, float d)
{
    if (a > b) 
    {
        float temp = a;
        a = b;
        b = temp;
    }

	if (c > d) 
    {
        float temp = c;
        c = d;
        d = temp;
    }

	return max (a, c) <= min (b, d);
}

float area (vec2 a, vec2 b, vec2 c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 