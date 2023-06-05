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

typedef struct {
    float r, g, b;
} Color;

typedef struct shader_s shader_t;

enum SHADERS {
    FLAT2D = 0,
    FLAT3D,
    FLAT_LIGHT,
    FLAT_OUTLINE
};

class Shader
{
public:
    Shader(char const *vertexShaderSourcePath, char const *fragmentShaderSourcePath);
    ~Shader();

    unsigned int id;

    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setColor(const std::string &name, Color color) const;
    void setTransform(const std::string &name, glm::mat4 transform) const;
    void setVec3(const std::string &name, glm::vec3 vec) const;
};

Color rainbow(float time);
