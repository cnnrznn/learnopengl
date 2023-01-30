#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>

#include "util.h"

int main()
{
    GLFWwindow* window = createWindow(1280, 720);
    
    uint shaderProgram = compileShaderProgram(
        "shaders_shaders/vert_shader.vs",
        "shaders_shaders/frag_shader.fs"
    );

    float vertices[] = {
        // positions         // colors
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 2,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 4,  // bottom left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 0,   // top 
    };

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Load buffer data and assign to attribute index
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3*sizeof(float)));
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(6*sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glUseProgram(shaderProgram);

    std::cout << "Set buffer data" << std::endl;

    double lastTime = glfwGetTime();
    int nbFrames = 0;

    while (!glfwWindowShouldClose(window))
    {
        nbFrames++;
        double currentTime = glfwGetTime();
        if (currentTime - lastTime >= 1.0) {
            printf("%d fps\n", nbFrames);
            nbFrames = 0;
            lastTime = currentTime;
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float timeValue = glfwGetTime() * 4;
        float offset = (sin(timeValue) / 2.0f);
        int offsetLocation = glGetUniformLocation(shaderProgram, "offset");
        glUniform1f(offsetLocation, offset);
        glUniform1f(glGetUniformLocation(shaderProgram, "time"), glfwGetTime());

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}