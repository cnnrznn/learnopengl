#version 330 core

out vec4 FragColor;  
in vec3 ourColor;
in float cycle;

uniform float time;

#define pi 3.14159
  
void main()
{
    //FragColor = vec4(ourColor, 1.0);

    int c1 = 2;
    int c2 = 4;
    if (cycle > 3) {
        c1 = 4;
        c2 = 2;
    }

    FragColor = vec4(
        0.5 + sin(((cycle * pi / 3) + time)),
        0.5 + sin((((cycle+2) * pi / 3) + time)),
        0.5 + sin((((cycle+4) * pi / 3) + time)),
        1.0
    );
}