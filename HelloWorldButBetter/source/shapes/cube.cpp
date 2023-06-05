/*
** EPITECH PROJECT, 2023
** HelloWorldButBetter
** File description:
** cube
*/

#include "../include/main.hpp"

void Renderer::cube()
{
    this->SHADERS[FLAT3D].shader.use();
    this->SHADERS[FLAT3D].shader.setColor("Color", rainbow(glfwGetTime()));
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    // note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    this->SHADERS[FLAT3D].shader.setTransform("model", model);
    this->SHADERS[FLAT3D].shader.setTransform("view", view);
    this->SHADERS[FLAT3D].shader.setTransform("projection", projection);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, TEXTURES[WOOD_CONTAINER]);
    glBindVertexArray(SHAPES_VAO[RECTANGLE]);
    glDrawElements(GL_TRIANGLES, SHAPES_VERTICES[RECTANGLE].size / sizeof(float) / 2, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}