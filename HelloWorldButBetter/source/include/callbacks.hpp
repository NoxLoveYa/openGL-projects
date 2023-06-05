/*
** EPITECH PROJECT, 2023
** HelloWorld
** File description:
** callbacks
*/

#pragma once

#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void register_callbacks(GLFWwindow *window);
