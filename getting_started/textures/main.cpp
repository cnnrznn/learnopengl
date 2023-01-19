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
    if (data == NULL) {
        // cleanup and exit
        return 1;
    }

    // load image into opengl 2d texture
    uint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    glfwTerminate();
    return 0;
}
