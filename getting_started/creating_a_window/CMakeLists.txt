add_executable(creating-a-window main.cpp)

find_package(OpenGL REQUIRED)

target_link_libraries(creating-a-window glfw)
target_link_libraries(creating-a-window glad)