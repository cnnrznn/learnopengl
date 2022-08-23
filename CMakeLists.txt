cmake_minimum_required(VERSION 3.0.0)
project(learnopengl VERSION 0.1.0)

# GLFW stuff
include_directories(glfw-3.3.8/include)
add_subdirectory(glfw-3.3.8)

# GLAD driver loader
add_subdirectory(glad)

# Tutorials
add_subdirectory(getting_started)

# Utility library
add_subdirectory(util)

# Hello world
add_executable(learnopengl main.cpp)