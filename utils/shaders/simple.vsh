#version 330 core

layout (location = 0) in vec4 position;

uniform mat4 pr_matrix;

out vec4 fs_Position;

void main() {
    gl_Position = pr_matrix * position;
    fs_Position = position;
}