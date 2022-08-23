# A template directory for populating chapter source code

add_executable(hello-triangle main.cpp shaders.cpp)

target_link_libraries(hello-triangle glfw)
target_link_libraries(hello-triangle glad)