#version 330

uniform float time;

out vec4 finalColor;

void main()
{
    finalColor = vec4(abs(sin(time)),0.0,0.0, 1.0);
}
