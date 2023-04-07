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
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f,
            0.0f, 0.5f, 0.0f,
    };

    float rectangleVertices[] = {
        0.5f, 0.5f, 0.0f, // top right
        0.5f, -0.5f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f // top left
    };

    this->SHAPES_VERTICES.push_back({triangleVertices, sizeof(triangleVertices)});
    this->SHAPES_VERTICES.push_back({rectangleVertices, sizeof(rectangleVertices)});

    this->SHAPES_SHADERS.push_back(getShaderProgram("source/shaders/source/simpleVertex.vert", "source/shaders/source/simpleFragment.frag"));
    this->SHAPES_SHADERS.push_back(getShaderProgram("source/shaders/source/simpleVertex.vert", "source/shaders/source/simpleFragment.frag"));

    this->SHAPES_VAO.push_back(getTriangleVao(this->SHAPES_VERTICES[TRIANGLE]));
    this->SHAPES_VAO.push_back(getRectangleVAO(this->SHAPES_VERTICES[RECTANGLE]));
}

Renderer::~Renderer()
{
    this->SHAPES_SHADERS.clear();
    this->SHAPES_VAO.clear();
}
