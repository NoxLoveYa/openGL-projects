/*
** EPITECH PROJECT, 2023
** HelloWorld
** File description:
** shapes
*/

#include "../include/main.hpp"

void initShapesVao()
{
    SHAPES_VAO->push_back(getTriangleVao());
    SHAPES_VAO->push_back(getSquareVao());

    std::cout << "initShapesVao: " << SHAPES_VAO->size() << std::endl;
}
