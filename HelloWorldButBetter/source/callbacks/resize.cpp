/*
** EPITECH PROJECT, 2023
** HelloWorld
** File description:
** resize
*/

#include "../include/callbacks.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
