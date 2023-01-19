#include <string>

typedef unsigned int uint;

char* shaderFromFile(char* fn);

uint compileShaderProgram(
    const char* vertexShaderFn,
    const char* fragmentShaderFn
);

GLFWwindow* createWindow(int width, int height);