#version 330 core

layout(location = 0) in vec4 s_vPosition;

uniform mat4 pr_matrix;

in vec4 s_vColor;

out vec4 s_fColor;

void main() {
    gl_Position = pr_matrix * s_vPosition;

    s_fColor = s_vColor;
}