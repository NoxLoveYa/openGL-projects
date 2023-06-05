#version 330 core

in vec3 fragColor;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main()
{
    FragColor = vec4(fragColor, 1.0);
}
