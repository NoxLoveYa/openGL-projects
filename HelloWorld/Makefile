##
## EPITECH PROJECT, 2023
## openGl
## File description:
## Makefile generator
##

SRC = $(wildcard source/*.c source/*.cpp source/callbacks/*.cpp source/shapes/*.cpp source/shaders/*.cpp)
TARGET = hello_world

all : $(TARGET)

$(TARGET) :
	g++ -o $@ $(SRC) -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl

fclean :
	$(RM) $(TARGET)

re : fclean all
