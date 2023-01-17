#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "util.h"

char* shaderFromFile(char* fn)
{
    std::ifstream file(fn);
    std::string contents(
        (std::istreambuf_iterator<char>(file)),
        (std::istreambuf_iterator<char>()));

    char* result = new char[contents.size() + 1];
    strcpy(result, contents.c_str());

    return result;
}

uint compileShaderProgram(
    char* vertexShaderFn,
    char* fragmentShaderFn
){
    char* vertexShaderSrc = shaderFromFile(vertexShaderFn);
    char* fragmentShaderSrc = shaderFromFile(fragmentShaderFn);

    uint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSrc, NULL);
    glCompileShader(vertexShader);

    uint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSrc, NULL);
    glCompileShader(fragmentShader);

    uint shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // cleanup
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void window_resize_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

GLFWwindow* createWindow(int width, int height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Error creating GLFW window" << std::endl;
        return NULL;
    }

    glfwSetFramebufferSizeCallback(window, window_resize_callback);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }

    glViewport(0,0,width, height);

    // Uncomment the below line if you want an un-capped framerate.
    // By default, on my machine, vsync is on.
    //
    // https://stackoverflow.com/questions/11312318/my-limited-fps-60
    // https://www.glfw.org/docs/3.3/group__context.html
    //
    //glfwSwapInterval(0);

    return window;
}
