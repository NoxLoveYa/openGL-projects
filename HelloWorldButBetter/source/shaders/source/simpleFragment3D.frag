#version 330 core

in vec3 color;
in vec3 lightColor;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main()
{
    float ambientStrength = 0.1;

    vec3 ambient = ambientStrength * lightColor;
    
    vec3 result = ambient * color;

    FragColor = texture(ourTexture, TexCoord) * vec4(result, 1.0);
}