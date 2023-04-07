/*
** EPITECH PROJECT, 2023
** HelloWorldButBetter
** File description:
** shaders
*/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
    Shader(char const *vertexShaderSourcePath, char const *fragmentShaderSourcePath);
    ~Shader();

    unsigned int id;

    void use();
};
