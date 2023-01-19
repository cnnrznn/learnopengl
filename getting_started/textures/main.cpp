#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "util.h"
#include "stb_image.h"

int main()
{
    GLFWwindow* window = createWindow(1280, 720);

    // load wooden texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0); 

    glfwTerminate();
    return 0;
}
