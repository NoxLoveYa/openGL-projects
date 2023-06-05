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

typedef struct shader_s {
    const char *id;
    Shader shader;
} shader_t;

class RectangleShape
{
public:
    RectangleShape();
    ~RectangleShape();

    shape_t vertices;
    int vao;
    shader_t shader;
};

class Renderer
{
public:
    Renderer();
    ~Renderer();

    std::vector<shape_t> SHAPES_VERTICES;
    std::vector<unsigned int> SHAPES_VAO;
    std::vector<unsigned int> TEXTURES;
    std::vector<shader_t> SHADERS;

    void triangle();
    void rectangle();
    void cube(glm::vec3 Position, int i);
};
