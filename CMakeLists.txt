# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Raccoon.cpp Raccoon.h RaccoonMethods.cpp RaccoonMethods.h ProgramMethods.cpp ProgramMethods.h Item.cpp Item.h)