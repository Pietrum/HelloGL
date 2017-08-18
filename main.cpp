#include <vector>

#include "src/graphics/Window.h"
#include "src/graphics/Shader.h"

#include "src/graphics/renderers/Sprite2D.h"
#include "src/graphics/renderers/BatchRenderer2D.h"

int main() {
    using namespace graphics;
    using namespace maths;

    Window window(960, 540, "HelloGL");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    renderers::BatchRenderer2D renderer;
    std::vector<renderers::Renderable2D*> sprites;

    for (int y = 0; y < 900; y += 5) {
        for (int x = 0; x < 1600; x += 5) {
            sprites.push_back(
                new renderers::Sprite2D(0.04f, 0.04f, (float) x / 100 , (float) y / 100, Vec4(0.0f, 1.0f, 1.0f, 1.0f))
            );
        }
    }

    std::cout << "Number of sprites: " << sprites.size() << std::endl;

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    Shader shader("../src/utils/shaders/simple.vsh", "../src/utils/shaders/simple.fsh");
    auto positionId = (GLuint) glGetAttribLocation(shader.m_ShaderID, "position");
    glVertexAttribPointer(positionId, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(positionId);
    shader.enable();
    Mat4 orthographic = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    shader.setUniformMat4("pr_matrix", orthographic);

    while (!window.closed()) {
        window.clear();

        Vec2 pointer((float)(Input::Mouse::x * 16.0f / 960.0f), (float)(9.0f - Input::Mouse::y * 9.0f / 540.0f));
        shader.setUniform2f("light_pos", pointer);

        for (auto &sprite : sprites) {
            renderer.submit(sprite);
        }
        renderer.flush();

        window.update();
    }

    return 0;
}