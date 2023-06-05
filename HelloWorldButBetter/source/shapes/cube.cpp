/*
** EPITECH PROJECT, 2023
** HelloWorldButBetter
** File description:
** cube
*/

#include "../include/main.hpp"

unsigned int getCubeVAO(shape_t &shape)
{
    unsigned int VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, shape.size, shape.vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    return VAO;
}

void Renderer::cube(glm::vec3 Position, int i)
{
    this->SHADERS[FLAT3D].shader.use();

    this->SHADERS[FLAT3D].shader.setColor("Color", rainbow(glfwGetTime()));

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::translate(model, Position);
    float angle = 20.0f * i; 
    model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

    view = glm::lookAt(this->cameraPos, this->cameraPos + this->cameraFront, glm::vec3(0.0f, 1.0f, 0.0f));

    projection = glm::perspective(glm::radians(this->fov), 1920.0f / 1080.0f, 0.1f, 100.0f);

    this->SHADERS[FLAT3D].shader.setTransform("model", model);
    this->SHADERS[FLAT3D].shader.setTransform("view", view);
    this->SHADERS[FLAT3D].shader.setTransform("projection", projection);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, TEXTURES[WOOD_CONTAINER]);

    glBindVertexArray(SHAPES_VAO[CUBE]);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(0);
}