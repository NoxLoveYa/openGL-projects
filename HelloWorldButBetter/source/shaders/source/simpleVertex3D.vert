#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;

uniform vec3 Color;
uniform vec3 LightColor;
uniform vec3 LightPos;

uniform vec3 ViewPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 fragColor;
out vec3 lightColor;

out vec3 lightPos;
out vec3 fragPos;

out vec3 viewPos;

out vec3 normal;

out vec2 texCoord;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);

    fragColor = Color;
    lightColor = LightColor;

    lightPos = LightPos;
    fragPos = vec3(model * vec4(aPos, 1.0));

    viewPos = ViewPos;

    normal = mat3(transpose(inverse(model))) * aNormal;

    texCoord = aTexCoord;
}
