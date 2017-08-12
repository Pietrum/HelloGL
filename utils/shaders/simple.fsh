#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 colour;
uniform vec2 light_pos;

in vec4 fs_Position;

void main() {
    color = colour / length(fs_Position.xy - light_pos);
}