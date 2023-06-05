#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform vec3 Color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 ourColor;
out vec2 TexCoord;

void main()
{
    gl_Position = projection * view * model * vec4(aPos.xyz, 1.0);
    ourColor = Color;
    TexCoord = aTexCoord;
}
