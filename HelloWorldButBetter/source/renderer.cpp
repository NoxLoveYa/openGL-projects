/*
** EPITECH PROJECT, 2023
** HelloWorldButBetter
** File description:
** render
*/

#include "include/main.hpp"
#include "include/renderer.hpp"


Renderer::Renderer()
{
    float triangleVertices[] = {
        // positions // colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// bottom left
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // top
    };

    float rectangleVertices[] = {
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,// top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,// bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f// top left
    };

    float triangleTexCoords[] = {
        0.0f, 0.0f,  // lower-left corner  
        1.0f, 0.0f,  // lower-right corner
        0.5f, 1.0f   // top-center corner
    };

    float rectangleTexCoords[] = {
        0.0f, 1.0f,  // top-left corner  
        1.0f, 1.0f,  // top-right corner
        1.0f, 0.0f,   // lower-right corner
        0.0f, 0.0f   // lower-left corner
    };

    this->SHAPES_VERTICES.push_back({triangleVertices, sizeof(triangleVertices), triangleTexCoords});
    this->SHAPES_VERTICES.push_back({rectangleVertices, sizeof(rectangleVertices), rectangleTexCoords});

    Shader flat("source/shaders/source/simpleVertex.vert", "source/shaders/source/simpleFragment.frag");
    std::string flatId = "flat";

    this->SHADERS.push_back((shader_t){flatId.c_str(), flat});

    this->SHAPES_VAO.push_back(getTriangleVao(this->SHAPES_VERTICES[TRIANGLE]));
    this->SHAPES_VAO.push_back(getRectangleVAO(this->SHAPES_VERTICES[RECTANGLE]));
}

Renderer::~Renderer()
{
    this->SHADERS.clear();
    this->SHAPES_VAO.clear();
}
