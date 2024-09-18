#version 330

uniform float u_time;

out vec4 finalColor;

void main()
{
    finalColor = vec4(abs(sin(u_time)),0.0,0.0, 1.0);
}
