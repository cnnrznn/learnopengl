add_library(util util.cpp stb_image.cpp)

target_link_libraries(util glfw)
target_link_libraries(util glad)