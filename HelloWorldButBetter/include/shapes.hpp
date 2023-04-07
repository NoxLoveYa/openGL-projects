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

static std::vector<unsigned int> *SHAPES_VAO = new std::vector<unsigned int>;

unsigned int getTriangleVao();
unsigned int getSquareVao();
void initShapesVao();

void renderTriangle();
