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

bool need_draw ()
{
    vec2 light_pos = vec2 (light.x / resolution.x, light.y / resolution.y);
    vec2 curr_pos = gl_TexCoord[0].st;
    vec2 global_pos = vec2 ((offset.x + curr_pos.x * tex_size.x) / resolution.x, (offset.y + curr_pos.y * tex_size.y) / resolution.y);

    for (int i = 0; i < bounds_size; i++)
    {
        
    }

    return true;
}

vec2 int_to_float (vec2 pos)
{
    return vec2 (pos.x / resolution.x, pos.y / resolution.y);
}

bool intersect (vec2 v11, vec2 v12, vec2 v21, vec2 v22)
{
    vec3 cut1 = vec3 (v12 - v11, 0);
    vec3 cut2 = vec3 (v22 - v21, 0);

    vec3 vv11 = vec3 (v11, 0);
    vec3 vv12 = vec3 (v12, 0);
    vec3 vv21 = vec3 (v21, 0);
    vec3 vv22 = vec3 (v22, 0);

    vec3 prod1 = cross (cut1.xy * (v21 - v11));

    return true;
}