#include "VertexBuffer.h"

namespace graphics { namespace buffers {
    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &m_ID);

        bind();
        glBufferData(GL_ARRAY_BUFFER, BUFFER_MAX_SIZE, nullptr, GL_DYNAMIC_DRAW);
        unbind();
    }

    VertexBuffer::VertexBuffer(GLfloat* data, GLsizei count, GLuint size)
        : m_Size(size) {
        glGenBuffers(1, &m_ID);

        bind();
        glBufferData(GL_ARRAY_BUFFER, count * size * sizeof(GLfloat), data, GL_STATIC_DRAW);
        unbind();
    }

    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &m_ID);
    }

    void VertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    }

    void VertexBuffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}}
