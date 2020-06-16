#define shade_res 10.0

uniform float frame;

uniform bool lanthern;

uniform vec2 bounds[64];
uniform vec3 light;

uniform int bounds_size;

uniform sampler2D current;
uniform sampler2D normal;

uniform bool use_normal;

uniform vec2 offset;
uniform vec2 tex_size;

float shade ();
bool intersect_1 (float a, float b, float c, float d);
float area (vec2 a, vec2 b, vec2 c);
bool intersect (vec2 a, vec2 b, vec2 c, vec2 d);
float diffuse ();
float light_animate ();

void main ()
{
    light.z += light_animate();

    vec2 light_pos = vec2 (light.x, 1080.0 - light.y);
    float dist = distance(gl_FragCoord.xy, light_pos);

    float shade_factor = shade();

    if (dist > light.z || !shade_factor)
    {
        gl_FragColor = vec4 (0.0, 0.0, 0.0, 1.0);
        return;
    }

    vec4 color = texture2D (current, gl_TexCoord[0].st);

    color = color + vec4 (0.1 - dist / light.z / 1000.0, 0.05 - dist / light.z / 1000.0, 0.0, 0.0);

    gl_FragColor = color * (1.0 - dist / light.z) * (1.0 - dist / light.z) * diffuse() * shade_factor;
}

float shade ()
{
    vec2 curr_pos = gl_TexCoord[0].st;
    vec2 global_pos = vec2 (offset.x + curr_pos.x * tex_size.x, offset.y + curr_pos.y * tex_size.y);

    float shade_factor = 1.0;

    for (float a = 0.0; a < 3.1415 * 2.0; a += 3.1415 / (shade_res / 2.0))
    {
        for (int i = 0; i < bounds_size; i++)
        {
            vec2 offsetlight = light.xy + vec2 (cos(a) * light.z / 200, sin(a) * light.z / 200);

            if (intersect (global_pos, offsetlight.xy, bounds[i * 4], bounds[i * 4 + 1]) ||
               intersect (global_pos, offsetlight.xy, bounds[i * 4 + 1], bounds [i * 4 + 2]) ||
               intersect (global_pos, offsetlight.xy, bounds[i * 4 + 2], bounds [i * 4 + 3]) ||
               intersect (global_pos, offsetlight.xy, bounds[i * 4 + 3], bounds [i * 4]))
               shade_factor -= 1.0 / shade_res;
        }
    }
   

    return shade_factor;
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

float diffuse ()
{
    if (!use_normal)
        return 1.0;

    vec2 pixel = gl_FragCoord.xy / tex_size.xy;

    vec3 NormalVector = texture2D (normal, pixel).xyz;
    vec3 LightVector = vec3 (light.x - gl_FragCoord.x, (1080 - light.y) - gl_FragCoord.y, light.z / 10);

    NormalVector.x -= 0.5;
    NormalVector.y -= 0.5;

    NormalVector = normalize(NormalVector);
    LightVector = normalize(LightVector);

    float diff = dot (NormalVector, LightVector);

    return diff;
}
 

float light_animate ()
{
    float T = 400.0;
    float offset = sin (3.1415 / T * frame) * sin (3.1415 / (T / 4) * frame) * sin (3.1415 / (T / 16) * frame) * 300;

    return offset;
}