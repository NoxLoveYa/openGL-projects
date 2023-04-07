/*
** EPITECH PROJECT, 2023
** HelloWorldButBetter
** File description:
** renderer
*/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer
{
public:
    Renderer();
    ~Renderer();

    std::vector<unsigned int> SHAPES_VAO;
    std::vector<unsigned int> SHAPES_SHADERS;

    void triangle();
    void rectangle();
};