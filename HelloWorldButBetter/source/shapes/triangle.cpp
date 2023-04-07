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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    return VAO;
}

void Renderer::triangle()
{
    glUseProgram(SHAPES_SHADERS[TRIANGLE]);
    glBindVertexArray(SHAPES_VAO[TRIANGLE]);
    glDrawArrays(GL_TRIANGLES, 0, SHAPES_VERTICES[TRIANGLE].size / sizeof(float) / 2);
    glBindVertexArray(0);
}
