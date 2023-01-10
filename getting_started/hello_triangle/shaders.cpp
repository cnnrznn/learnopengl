const char* vertex_shader = "\
#version 330 core\
layout (location = 0) in vec3 aPos;\
\
void main()\
{\
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\
}\
";

const char* fragment_shader = "\
#version 330 core\
out vec4 fragColor;\
\
void main()\
{\
    fragColor = vec4(1.0f, 0.5f, 0.2f, 0.7f);\
}\
";