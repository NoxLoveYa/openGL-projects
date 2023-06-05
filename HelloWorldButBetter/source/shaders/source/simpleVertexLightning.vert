#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform vec3 Color;
uniform vec3 LightColor;
uniform vec3 LightPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 color;
out vec3 lightColor;
out vec2 texCoord;

void main()
{
    gl_Position = projection * view * model * vec4(aPos.xyz, 1.0);
    color = Color;
    lightColor = LightColor;
    texCoord = aTexCoord;
}
