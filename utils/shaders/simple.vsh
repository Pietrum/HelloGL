#version 330 core

layout(location = 0) in vec3 s_vPosition;

in vec4 s_vColor;

out vec4 s_fColor;

void main() {
    gl_Position.xyz = s_vPosition;
    gl_Position.w = 1;

    s_fColor = s_vColor;
}