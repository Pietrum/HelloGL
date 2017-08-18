#include "IndexBuffer.h"

namespace graphics { namespace buffers {
    IndexBuffer::IndexBuffer() {
        glGenBuffers(1, &m_ID);
    }

    IndexBuffer::IndexBuffer(GLuint *data, GLsizei count) {
        glGenBuffers(1, &m_ID);

        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
        unbind();
    }

    IndexBuffer::IndexBuffer(GLushort *data, GLsizei count) {
        glGenBuffers(1, &m_ID);

        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
        unbind();
    }

    IndexBuffer::~IndexBuffer() {
        glDeleteBuffers(1, &m_ID);
    }

    void IndexBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
    }

    void IndexBuffer::unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}}
