#include "graphics/Window.h"
#include "graphics/Shader.h"
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

    static const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
    };

    Shader shader("../utils/shaders/simple.vsh", "../utils/shaders/simple.fsh");

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), nullptr, GL_STATIC_DRAW);

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);

    auto positionId = (GLuint) glGetAttribLocation(shader.m_ShaderID, "s_vPosition");
    auto colorId = (GLuint) glGetAttribLocation(shader.m_ShaderID, "s_vColor");

    glVertexAttribPointer(positionId, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glVertexAttribPointer(colorId, 4, GL_FLOAT, GL_FALSE, 0, (char *) nullptr + sizeof(vertices));

    shader.enable();
    glEnableVertexAttribArray(positionId);
    glEnableVertexAttribArray(colorId);

    Mat4 orthographic = Mat4::orthographic(-8.0f, 8.0f, -4.5f, 4.5f, -1.0f, 1.0f);
    shader.setUniformMat4("pr_matrix", orthographic);

    while (!window.closed()) {
        window.clear();

        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.update();
    }

    return 0;
}