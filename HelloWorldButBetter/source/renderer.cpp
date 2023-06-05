/*
** EPITECH PROJECT, 2023
** HelloWorldButBetter
** File description:
** render
*/

#include "include/main.hpp"

Renderer::Renderer()
{
    float triangleVertices[] = {
        // positions // colors // texture coords
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,// bottom left
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 1.0f // top
    };

    float rectangleVertices[] = {
        // positions // colors // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,// top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,// bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,// bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f// top left
    };

    this->SHAPES_VERTICES.push_back({triangleVertices, sizeof(triangleVertices)});
    this->SHAPES_VERTICES.push_back({rectangleVertices, sizeof(rectangleVertices)});

    Shader flat("source/shaders/source/simpleVertex.vert", "source/shaders/source/simpleFragment.frag");
    std::string flatId = "flat";

    this->SHADERS.push_back((shader_t){flatId.c_str(), flat});

    this->SHAPES_VAO.push_back(getTriangleVao(this->SHAPES_VERTICES[TRIANGLE]));
    this->SHAPES_VAO.push_back(getRectangleVAO(this->SHAPES_VERTICES[RECTANGLE]));

    this->TEXTURES.push_back(loadTexture("source/textures/source/brick_wall.jpg"));
    this->TEXTURES.push_back(loadTexture("source/textures/source/wood_container.jpg"));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

Renderer::~Renderer()
{
    this->SHADERS.clear();
    this->SHAPES_VAO.clear();
}
