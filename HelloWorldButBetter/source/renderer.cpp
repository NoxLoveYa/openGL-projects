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

    this->SHAPES_VERTICES.push_back({triangleVertices, sizeof(triangleVertices)});
    this->SHAPES_VERTICES.push_back({rectangleVertices, sizeof(rectangleVertices)});

    Shader triangleShader("source/shaders/source/simpleVertex.vert", "source/shaders/source/simpleFragment.frag");
    Shader rectangleShader("source/shaders/source/simpleVertex.vert", "source/shaders/source/simpleFragment.frag");

    this->SHAPES_SHADERS.push_back(triangleShader);
    this->SHAPES_SHADERS.push_back(rectangleShader);

    this->SHAPES_VAO.push_back(getTriangleVao(this->SHAPES_VERTICES[TRIANGLE]));
    this->SHAPES_VAO.push_back(getRectangleVAO(this->SHAPES_VERTICES[RECTANGLE]));
}

Renderer::~Renderer()
{
    this->SHAPES_SHADERS.clear();
    this->SHAPES_VAO.clear();
}
