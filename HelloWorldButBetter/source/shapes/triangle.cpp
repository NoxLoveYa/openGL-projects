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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2); 

    return VAO;
}

void Renderer::triangle()
{
    glUseProgram(this->SHADERS[FLAT2D].shader.id);
    this->SHADERS[FLAT2D].shader.setColor("Color", (Color){1.0f, 1.0f, 1.0f});
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
    this->SHADERS[TRIANGLE].shader.setTransform("transform", trans);
    glBindTexture(GL_TEXTURE_2D, TEXTURES[WOOD_CONTAINER]);
    glBindVertexArray(SHAPES_VAO[TRIANGLE]);
    glDrawArrays(GL_TRIANGLES, 0, SHAPES_VERTICES[TRIANGLE].size / sizeof(float) / 2);
    glBindVertexArray(0);
}
