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

unsigned int getShaderProgram(char const *vertexShaderSourcePath, char const *fragmentShaderSourcePath);
