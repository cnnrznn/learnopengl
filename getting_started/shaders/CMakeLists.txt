# Shaders tutorial https://learnopengl.com/Getting-started/Shaders

add_executable(shaders main.cpp)

target_link_libraries(shaders util)
target_link_libraries(shaders glfw)
target_link_libraries(shaders glad)

install(DIRECTORY shaders_shaders
    DESTINATION bin
)

install(TARGETS shaders)