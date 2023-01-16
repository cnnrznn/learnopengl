#include <string>

typedef unsigned int uint;

char* shaderFromFile(char* fn);

uint compileShaderProgram(
    char* vertexShaderFn,
    char* fragmentShaderFn
);

GLFWwindow* createWindow(int width, int height);