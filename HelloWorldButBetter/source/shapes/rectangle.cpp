/*
** EPITECH PROJECT, 2023
** HelloWorldButBetter
** File description:
** rectangle
*/

#include "../include/main.hpp"

unsigned int getRectangleVAO(shape_t &shape)
{
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3 // second triangle
    };

    unsigned int VBO, EBO, VAO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, shape.size, shape.vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    return VAO;
}

void Renderer::rectangle()
{
    glUseProgram(SHAPES_SHADERS[RECTANGLE]);
    glBindVertexArray(SHAPES_VAO[RECTANGLE]);
    glDrawElements(GL_TRIANGLES, SHAPES_VERTICES[RECTANGLE].size / sizeof(float) / 2, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
