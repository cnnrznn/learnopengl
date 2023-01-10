#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string.h>

#include "shaders.h"

GLFWwindow* init();
void fini();
void render(GLFWwindow*);

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

int main()
{
    std::cout << "Hello triangle!" << std::endl;

    GLFWwindow* window = init();
    if (!window) {
        std::cout << "Error creating window" << std::endl;
    }

    render(window);

    fini();

    return 0;
}

void render(GLFWwindow* window)
{
    std::cout << "Called render()" << std::endl;
    std::cout << window << std::endl;

    int success;
    char infoLog[512];

    if (window == NULL)
    {
        std::cout << "Will not render to a null window" << std::endl;
        return;
    }

    std::cout << "Compiling vertex shader..." << std::endl;
    std::cout << strlen(vertex_shader) << std::endl;

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_shader, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    std::cout << "Compiled vertex shader" << std::endl;

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 1024, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    std::cout << "Compiled fragment shader" << std::endl;

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 1024, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }
    std::cout << "Linked shader program" << std::endl;

    // cleanup
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    std::cout << "Set buffer data" << std::endl;


    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

GLFWwindow* init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "A window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Error creating GLFW window" << std::endl;
        return NULL;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }

    glViewport(0,0,SCR_WIDTH, SCR_HEIGHT);

    return window;
}

void fini()
{
    glfwTerminate();
}