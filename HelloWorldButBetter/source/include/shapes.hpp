/*
** EPITECH PROJECT, 2023
** HelloWorld
** File description:
** shapes
*/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum SHAPES {
    TRIANGLE = 0,
    SQUARE
};

unsigned int getTriangleVao();
