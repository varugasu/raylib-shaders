# Shader Playground with Raylib

A `.fs` file is a **Fragment Shader**. The output of this fragment is the color expected

When we do:

```fs
finalColor = vec4(1.0,0.0,0.0, 1.0);
```

We are setting all pixels to RED

It is also possible to change values over time using `uniform float time;`

We can pass the time by using the `ShaderSetValue` function:

```cpp
float time = GetTime();
SetShaderValue(
    shader, GetShaderLocation(shader, "time"),
    &time, SHADER_UNIFORM_FLOAT);
```
