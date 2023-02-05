# Code for texture lesson
# https://learnopengl.com/Getting-started/Textures

add_executable(textures main.cpp)

target_link_libraries(textures glfw)
target_link_libraries(textures glad)
target_link_libraries(textures util)

install(TARGETS textures)

install(DIRECTORY textures_shaders
    DESTINATION bin
)
install(FILES container.jpg awesomeface.png
    DESTINATION bin
)