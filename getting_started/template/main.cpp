#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* init();
void fini();
void render(GLFWwindow*);


int main()
{
    GLFWwindow* window = init();
    render(window);
    fini();

    return 0;
}

void render(GLFWwindow* window)
{
    if (window == NULL)
    {
        std::cout << "Will not render to a null window" << std::endl;
        return;
    }

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
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

    GLFWwindow* window = glfwCreateWindow(800, 600, "A window", NULL, NULL);
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

    glViewport(0,0,800,600);

    return window;
}

void fini()
{
    glfwTerminate();
}