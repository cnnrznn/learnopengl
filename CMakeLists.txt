cmake_minimum_required(VERSION 3.0.0)
project(learnopengl VERSION 0.1.0)

include_directories(glfw-3.3.8/include)

add_subdirectory(glfw-3.3.8)

add_subdirectory(getting_started/creating_a_window)

add_executable(learnopengl main.cpp)