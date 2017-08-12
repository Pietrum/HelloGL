#include "graphics/Window.h"
#include "graphics/Shader.h"
#include "maths/Vec2.h"
#include "maths/Vec3.h"
#include "maths/Vec4.h"
#include "maths/Mat4.h"

int main() {
    using namespace graphics;

    Window window(960, 540, "HelloGL");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    static const GLfloat vertices[] = {
        -1.5f, -1.5f, 0.0f,
         1.5f, -1.5f, 0.0f,
         0.0f,  1.5f, 0.0f,
    };

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(vertices), vertices, GL_STATIC_DRAW);

    Shader shader("../utils/shaders/simple.vsh", "../utils/shaders/simple.fsh");
    auto positionId = (GLuint) glGetAttribLocation(shader.m_ShaderID, "position");
    glVertexAttribPointer(positionId, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(positionId);

    shader.enable();
    Mat4 orthographic = Mat4::orthographic(-8.0f, 8.0f, -4.5f, 4.5f, -1.0f, 1.0f);
    shader.setUniformMat4("pr_matrix", orthographic);

    Vec2 light_pos(0.0f, 0.0f);
    shader.setUniform2f("light_pos", light_pos);
    Vec4 colour(0.2f, 0.3f, 0.8f, 1.0f);
    shader.setUniform4f("colour", colour);

    while (!window.closed()) {
        window.clear();

        Vec2 pointer((float)(Input::Mouse::x * 16.0f / 960.0f - 8.0f), (float)(4.5f - Input::Mouse::y * 9.0f / 540.0f));
        shader.setUniform2f("light_pos", pointer);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.update();
    }

    return 0;
}