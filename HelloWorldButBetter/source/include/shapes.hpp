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
    RECTANGLE
};

typedef struct {
    float r, g, b;
} color_t;

typedef struct {
    float *vertices;
    int size;
    float *texCoords;
} shape_t;

unsigned int getTriangleVao(shape_t &shape);
unsigned int getRectangleVAO(shape_t &shape);
