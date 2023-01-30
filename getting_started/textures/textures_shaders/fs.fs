#version 330 core
out vec4 FragColor;

in vec2 ourPos; 
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform float time;

void main()
{
    float offset = (sin(time)+1)/2; // 0.0 to 1.0 scale
    FragColor = vec4(
        ourColor.x,
        ourColor.y,
        ourColor.z,
        1.0
    ) * texture(ourTexture, TexCoord);
}