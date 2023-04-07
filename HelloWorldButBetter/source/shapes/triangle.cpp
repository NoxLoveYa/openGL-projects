/*
** EPITECH PROJECT, 2023
** HelloWorld
** File description:
** triangle
*/

#include "../include/main.hpp"

unsigned int getTriangleVao()
{
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };

    unsigned int VBO, VAO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //copy vertices array in a buffer for OpenGL to use
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return VAO;
}

void Renderer::triangle()
{
    glUseProgram(SHAPES_SHADERS[TRIANGLE]);
    glBindVertexArray(SHAPES_VAO[TRIANGLE]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
