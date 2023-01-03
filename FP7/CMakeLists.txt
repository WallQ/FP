cmake_minimum_required(VERSION 3.24)
project(FP7 C)

set(CMAKE_C_STANDARD 17)

add_executable(FP7 main.c Part1/main.c Part1/menu.c Part1/menu.h Part1/input.c Part1/input.h Part1/student.c Part1/student.h Part2/main.c)
