cmake_minimum_required(VERSION 3.0.0)
project(learnopengl VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(glfw-3.3.7)

add_executable(learnopengl main.cpp)
include_directories(glfw-3.3.7/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
