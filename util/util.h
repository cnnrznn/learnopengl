typedef unsigned int uint;

uint compileShaderProgram(
    const char* vertexShaderSrc,
    const char* fragmentShaderSrc
);

GLFWwindow* createWindow(int width, int height);