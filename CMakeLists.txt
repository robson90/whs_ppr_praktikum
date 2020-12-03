cmake_minimum_required(VERSION 3.17)
project(ppr C)

set(CMAKE_C_STANDARD 89)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(ppr praktikum3/main.c)