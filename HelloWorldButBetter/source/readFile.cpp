/*
** EPITECH PROJECT, 2023
** HelloWorld
** File description:
** readFile
*/

#include "include/files.hpp"

void readShaderSource(const char *shaderPath, char **buffer)
{
    std::ifstream infile(shaderPath);

    if (!infile.is_open()) { // check if file was successfully opened
        std::cout << "Failed to open file " << shaderPath << std::endl;
        exit(84);
    }

    std::string file_contents((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));

    const char *shaderSource = file_contents.c_str();

    infile.close();

    (*buffer) = (char *)malloc(sizeof(char) * file_contents.length());
    std::strcpy(*buffer, file_contents.c_str());
}
