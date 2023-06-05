/*
** EPITECH PROJECT, 2023
** HelloWorldButBetter
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

    //check for errors
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

Shader::Shader(char const *vertexShaderSourcePath, char const *fragmentShaderSourcePath)
{
    this->id = getShaderProgram(vertexShaderSourcePath, fragmentShaderSourcePath);
}

Shader::~Shader()
{
}

void Shader::use()
{
    glUseProgram(this->id);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(this->id, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(this->id, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(this->id, name.c_str()), value);
}

void Shader::setColor(const std::string &name, Color color) const
{
    glUniform3f(glGetUniformLocation(this->id, name.c_str()), color.r, color.g, color.b);
}

void Shader::setTransform(const std::string &name, glm::mat4 transform) const
{
    glUniformMatrix4fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, glm::value_ptr(transform));
}

Color rainbow(float time)
{
    float frequency = 0.5f;
    Color color;
    color.r = 0.5f + 0.5f * std::sin(frequency * time);
    color.g = 0.5f + 0.5f * std::sin(frequency * time + 2.0f * M_PI / 3.0f);
    color.b = 0.5f + 0.5f * std::sin(frequency * time + 4.0f * M_PI / 3.0f);
    return color;
}
