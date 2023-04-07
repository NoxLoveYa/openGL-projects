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
    this->SHAPES_SHADERS.push_back(getShaderProgram("source/shaders/source/simpleVertex.vert", "source/shaders/source/simpleFragment.frag"));
    this->SHAPES_SHADERS.push_back(getShaderProgram("source/shaders/source/simpleVertex.vert", "source/shaders/source/simpleFragment.frag"));

    this->SHAPES_VAO.push_back(getTriangleVao());
    this->SHAPES_VAO.push_back(getRectangleVAO());
}

Renderer::~Renderer()
{
    this->SHAPES_SHADERS.clear();
    this->SHAPES_VAO.clear();
}
