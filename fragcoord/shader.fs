#version 330

uniform vec2 u_resolution;
uniform float u_time;

out vec4 finalColor;

void main()
{
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    finalColor = vec4(st,0.0, 1.0);
}
