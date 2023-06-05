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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    return VAO;
}

void Renderer::cube(glm::vec3 Position, glm::vec3 lightPosition, Color color, Color light_color, Shader shader)
{
    shader.use();

    shader.setColor("Color", color);
    shader.setColor("LightColor", light_color);

    shader.setVec3("LightPos", lightPosition);

    shader.setVec3("ViewPos", this->cameraPos);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::translate(model, Position);
    if (shader.id == this->SHADERS[FLAT_LIGHT].shader.id)
        model = glm::scale(model, glm::vec3(0.2f));

    view = glm::lookAt(this->cameraPos, this->cameraPos + this->cameraFront, this->cameraUp);

    projection = glm::perspective(glm::radians(this->fov), 1920.0f / 1080.0f, 0.1f, 100.0f);

    shader.setTransform("model", model);
    shader.setTransform("view", view);
    shader.setTransform("projection", projection);

    if (shader.id != this->SHADERS[FLAT_LIGHT].shader.id) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, TEXTURES[WOOD_CONTAINER]);
    }

    glBindVertexArray(SHAPES_VAO[CUBE]);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(0);
}