# Shader Playground with Raylib

A `.fs` file is a **Fragment Shader**. The output of this fragment is the color expected

When we do:

```glsl
finalColor = vec4(1.0,0.0,0.0, 1.0);
```

We are setting all pixels to RED

## Uniform u_time

It is also possible to change values over time using `uniform float time;`

We can pass the time by using the `ShaderSetValue` function:

```cpp
float time = GetTime();
SetShaderValue(
    shader, GetShaderLocation(shader, "time"),
    &time, SHADER_UNIFORM_FLOAT);
```

## gl_FragCoord and u_resolution

In `fragcoord.cpp`, we use the global `gl_FragCoord` that gets the exactly pixel the active thread is working on.
Therefore, the `gl_FragCoord` contains the `x`, `y`, and `z` of the current pixel.

If we use `gl_FragCoord.x` for the **red** color, and `gl_FragCoord.y` for the **green** color, we can easily visualize what the shader did on each pixel.

This means that:

- the top-left pixel will be pure green
- the top-right will be yellow, because it mixes green and red
- the bottom-right pixel will be pure red

This is done with:

```glsl
vec2 st = gl_FragCoord.xy/u_resolution.xy;
finalColor = vec4(st,0.0, 1.0);
```

`gl_FragCoord.xy/u_resolution.xy` normalize the coordinate to fit the value between `0.0` and `1.0`
