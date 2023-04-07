/*
** EPITECH PROJECT, 2023
** HelloWorld
** File description:
** shaders
*/

#include "../include/main.hpp"

unsigned int getShaderProgram(char const *vertexShaderSourcePath, char const *fragmentShaderSourcePath)
{
    char *vertexShaderSource, *fragmentShaderSource = NULL;

    readShaderSource(vertexShaderSourcePath, &vertexShaderSource);
    readShaderSource(fragmentShaderSourcePath, &fragmentShaderSource);

    //create shaders
    unsigned int SBO, FBO;

    SBO = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(SBO, 1, &vertexShaderSource, NULL);

    FBO = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FBO, 1, &fragmentShaderSource, NULL);

    //compile shaders
    glCompileShader(SBO);
    glCompileShader(FBO);

    //chcek for errors
    int success;
    char infoLog[512];

    glGetShaderiv(SBO, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(SBO, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
        infoLog << std::endl;
    }

    glGetShaderiv(FBO, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(FBO, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
        infoLog << std::endl;
    }

     //create shader program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    //attach shaders to program
    glAttachShader(shaderProgram, SBO);
    glAttachShader(shaderProgram, FBO);

    //link shaders
    glLinkProgram(shaderProgram);

    //check for errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" <<
        infoLog << std::endl;
    }

    //delete shaders
    glDeleteShader(SBO);
    glDeleteShader(FBO);

    return shaderProgram;
}

void initShaders()
{
    SHAPES_SHADERS->push_back(getShaderProgram("source/shaders/source/simpleVertex.vert", "source/shaders/source/simpleFragment.frag"));
    SHAPES_SHADERS->push_back(getShaderProgram("source/shaders/source/simpleVertex.vert", "source/shaders/source/simpleFragment.frag"));
}
