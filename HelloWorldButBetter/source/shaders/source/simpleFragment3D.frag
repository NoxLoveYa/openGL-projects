#version 330 core

in vec3 fragColor;
in vec3 lightColor;

in vec3 lightPos;
in vec3 fragPos;

in vec3 viewPos;

in vec3 normal;

in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D Texture;

void main()
{
    vec3 outlineColor = vec3(0, 0, 0);

    float ambientStrength = 0.1;
    float specularStrength = 0.5;

    vec3 norm = normalize(normal);

    vec3 lightDir = normalize(lightPos - fragPos);
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float diff = max(dot(norm, lightDir), 0.0);

    vec3 ambient = ambientStrength * lightColor;
    vec3 diffuse = diff * lightColor;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * fragColor;

    FragColor = texture(Texture, texCoord) * vec4(result, 1.0);
}