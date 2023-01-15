cmake_minimum_required(VERSION 3.0.0)
project(learnopengl VERSION 0.1.0)

# Include directory
include_directories(util)

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

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/bin)
install(TARGETS creating-a-window hello-triangle glfw glad util
    RUNTIME DESTINATION bin
)