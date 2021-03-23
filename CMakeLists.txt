cmake_minimum_required(VERSION 3.17)
project(ppr C)

set(CMAKE_C_STANDARD 99)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(ppr binaerbaeume/main.c binaerbaeume/btreenode.c binaerbaeume/btreenode.h binaerbaeume/btree.c binaerbaeume/btree.h binaerbaeume/frequency.c binaerbaeume/frequency.h)