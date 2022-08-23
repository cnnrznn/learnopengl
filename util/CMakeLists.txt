add_library(util util.cpp util.h)

target_link_libraries(util glfw)
target_link_libraries(util glad)