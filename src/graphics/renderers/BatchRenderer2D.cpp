#include "BatchRenderer2D.h"

namespace graphics { namespace renderers {
    BatchRenderer2D::BatchRenderer2D() {
        m_VAO = new buffers::VertexArray();
        m_VAO->bind();

        m_VBO = new buffers::VertexBuffer();
        m_VBO->bind();
        m_VAO->addAttrib(SHADER_VERTEX_INDEX, 3, 0);
        m_VAO->addAttrib(SHADER_COLOR_INDEX, 4, 3);
        m_VBO->unbind();

        auto * indices = new GLuint[BUFFER_INDICES_SIZE];
        for (int i = 0, offset = 0; i < BUFFER_INDICES_SIZE; i += 6) {
            indices[i + 0] = static_cast<GLuint>(offset);
            indices[i + 1] = static_cast<GLuint>(offset + 1);
            indices[i + 2] = static_cast<GLuint>(offset + 2);
            indices[i + 3] = static_cast<GLuint>(offset + 2);
            indices[i + 4] = static_cast<GLuint>(offset + 3);
            indices[i + 5] = static_cast<GLuint>(offset + 0);

            offset += 4;
        }

        m_IBO = new buffers::IndexBuffer(indices, BUFFER_INDICES_SIZE);
        m_VAO->unbind();
    }

    BatchRenderer2D::~BatchRenderer2D() {
        delete m_VAO;
        delete m_VBO;
        delete m_IBO;
    }

    void BatchRenderer2D::submit(const Renderable2D *renderable) {
        if (m_IBC == 0) {
            m_VBO->bind();
            m_Buffer = (buffers::VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
        }

        const maths::Vec3& position = renderable->getPosition();
        const maths::Vec2& size = renderable->getSize();
        const maths::Vec4& color = renderable->getColor();

        m_Buffer->vertex = position;
        m_Buffer->color = color;
        m_Buffer++;

        m_Buffer->vertex = maths::Vec3(position.x, position.y + size.y, position.z);
        m_Buffer->color = color;
        m_Buffer++;

        m_Buffer->vertex = maths::Vec3(position.x + size.x, position.y + size.y, position.z);
        m_Buffer->color = color;
        m_Buffer++;

        m_Buffer->vertex = maths::Vec3(position.x + size.x, position.y, position.z);
        m_Buffer->color = color;
        m_Buffer++;

        m_IBC += 6;
    }

    void BatchRenderer2D::flush() {
        // render frame
        m_VAO->bind();
        m_IBO->bind();

        glDrawElements(GL_TRIANGLES, m_IBC, GL_UNSIGNED_INT, nullptr);

        m_IBO->unbind();
        m_VAO->unbind();

        // prepare for the next frame
        glUnmapBuffer(GL_ARRAY_BUFFER);
        m_VBO->unbind();
        m_IBC = 0;
    }
}}
