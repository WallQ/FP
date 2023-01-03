cmake_minimum_required(VERSION 3.24)
project(FP8 C)

set(CMAKE_C_STANDARD 17)

add_executable(FP8 main.c input.c input.h menu.c menu.h student.c student.h)
