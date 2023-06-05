#version 330 core

in vec3 color;
in vec3 lightColor;
in vec2 texCoord;

out vec4 FragColor;

void main()
{
    FragColor = vec4(lightColor, 1.0);
}
