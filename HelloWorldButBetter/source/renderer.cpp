/*
** EPITECH PROJECT, 2023
** HelloWorldButBetter
** File description:
** render
*/

#include "include/main.hpp"

Renderer::Renderer()
{
    float triangleVertices[] = {
        // positions // colors // texture coords
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,// bottom left
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 1.0f // top
    };

    float rectangleVertices[] = {
        // positions // colors // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,// top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,// bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,// bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f// top left
    };

    float cubeVertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
        0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,   
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f
    };

    this->SHAPES_VERTICES.push_back({triangleVertices, sizeof(triangleVertices)});
    this->SHAPES_VERTICES.push_back({rectangleVertices, sizeof(rectangleVertices)});
    this->SHAPES_VERTICES.push_back({cubeVertices, sizeof(cubeVertices)});

    //2D flat shader
    Shader flat2D("source/shaders/source/simpleVertex2D.vert", "source/shaders/source/simpleFragment2D.frag");
    std::string flat2DId = "flat2D";
    this->SHADERS.push_back((shader_t){flat2DId.c_str(), flat2D});

    //3D flat shader
    Shader flat3D("source/shaders/source/simpleVertex3D.vert", "source/shaders/source/simpleFragment3D.frag");
    std::string flat3DId = "flat3D";
    this->SHADERS.push_back((shader_t){flat3DId.c_str(), flat3D});

    //3D flat light shader
    Shader flatLight("source/shaders/source/simpleVertexLightning.vert", "source/shaders/source/simpleFragmentLightning.frag");
    std::string flatLightId = "flatLight";
    this->SHADERS.push_back((shader_t){flatLightId.c_str(), flatLight});

    //3D flat light shader
    Shader flatOutline("source/shaders/source/simpleVertexLightning.vert", "source/shaders/source/flatNoTex.frag");
    std::string flatOutlineId = "flatOutline";
    this->SHADERS.push_back((shader_t){flatOutlineId.c_str(), flatOutline});

    this->SHAPES_VAO.push_back(getTriangleVao(this->SHAPES_VERTICES[TRIANGLE]));
    this->SHAPES_VAO.push_back(getRectangleVAO(this->SHAPES_VERTICES[RECTANGLE]));
    this->SHAPES_VAO.push_back(getCubeVAO(this->SHAPES_VERTICES[CUBE]));

    this->TEXTURES.push_back(loadTexture("source/textures/source/brick_wall.jpg"));
    this->TEXTURES.push_back(loadTexture("source/textures/source/wood_container.jpg"));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

Renderer::~Renderer()
{
    this->SHADERS.clear();
    this->SHAPES_VAO.clear();
}
