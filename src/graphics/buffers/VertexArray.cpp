#include "VertexArray.h"

namespace graphics { namespace buffers {
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_ID);
    }

    VertexArray::~VertexArray() {
        for (auto &m_Buffer : m_Buffers)
            delete m_Buffer;

        glDeleteVertexArrays(1, &m_ID);
    }

    void VertexArray::addBuffer(VertexBuffer *buffer, GLuint idx) {
        buffer->bind();
        glEnableVertexAttribArray(idx);
        glVertexAttribPointer(idx, buffer->getSize(), GL_FLOAT, GL_FALSE, 0, nullptr);
        buffer->unbind();
    }

    void VertexArray::addAttrib(GLuint idx, GLuint size, GLuint offset) {
        glEnableVertexAttribArray(idx);
        glVertexAttribPointer(idx, size, GL_FLOAT, GL_FALSE, BUFFER_VERTEX_SIZE, (const GLvoid*)(offset * sizeof(GLfloat)));
    }

    void VertexArray::bind() const {
        glBindVertexArray(m_ID);
    }

    void VertexArray::unbind() const {
        glBindVertexArray(0);
    }
}}