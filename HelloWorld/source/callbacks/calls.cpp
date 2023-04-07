/*
** EPITECH PROJECT, 2023
** HelloWorld
** File description:
** calls
*/

#include "../include/callbacks.hpp"

void register_callbacks(GLFWwindow *window)
{
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}
