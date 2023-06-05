#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform vec3 Color;

uniform mat4 transform;

out vec3 fragColor;
out vec2 TexCoord;

void main()
{
    gl_Position = transform * vec4(aPos.xyz, 1.0);
    fragColor = Color;
    TexCoord = aTexCoord;
}
