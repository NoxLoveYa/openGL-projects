#version 330 core

in vec3 color;
in vec3 lightColor;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, TexCoord) * vec4(color * lightColor, 1.0);
}