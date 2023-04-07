#version 330 core
uniform vec4 vertexColor;
out vec4 FragColor;
void main()
{
    FragColor = vertexColor;
}