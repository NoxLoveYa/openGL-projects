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

#include "shaders.hpp"
#include "shapes.hpp"
#include "glm/glm.hpp"

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

    float deltaTime = 0.0f;

    float fov = 45.0f;

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    float cameraSpeed = 2.5f;

    void triangle();
    void rectangle();
    void cube(glm::vec3 Position, int i);
};
