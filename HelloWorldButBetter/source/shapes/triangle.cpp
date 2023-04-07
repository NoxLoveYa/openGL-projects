/*
** EPITECH PROJECT, 2023
** HelloWorld
** File description:
** triangle
*/

#include "../include/main.hpp"

unsigned int getTriangleVao(shape_t &shape)
{
    unsigned int VBO, VAO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //copy vertices array in a buffer for OpenGL to use
    glBufferData(GL_ARRAY_BUFFER, shape.size, shape.vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return VAO;
}

void Renderer::triangle()
{
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    float redValue = (sin(timeValue) / 4.0f) + 0.5f;
    float blueValue = (sin(timeValue) / 3.0f) + 0.5f;
    int vertexColorLocation = glGetUniformLocation(SHAPES_SHADERS[TRIANGLE], "vertexColor");
    glUseProgram(SHAPES_SHADERS[TRIANGLE]);
    glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.f);
    glBindVertexArray(SHAPES_VAO[TRIANGLE]);
    glDrawArrays(GL_TRIANGLES, 0, SHAPES_VERTICES[TRIANGLE].size / sizeof(float) / 2);
    glBindVertexArray(0);
}
