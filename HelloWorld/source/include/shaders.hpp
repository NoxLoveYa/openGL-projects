/*
** EPITECH PROJECT, 2023
** HelloWorld
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

static std::vector<unsigned int> *SHAPES_SHADERS = new std::vector<unsigned int>;

unsigned int getShaderProgram(char const *vertexShaderSourcePath, char const *fragmentShaderSourcePath);

void initShaders();
