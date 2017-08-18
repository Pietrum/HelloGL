#ifndef CLIENT_VERTEXBUFFER_H
#define CLIENT_VERTEXBUFFER_H

#include "iBuffer.h"

namespace graphics { namespace buffers {
    class VertexBuffer : public iBuffer {
        GLuint m_Size;
    public:
        VertexBuffer();
        VertexBuffer(GLfloat*, GLsizei, GLuint);
        ~VertexBuffer();

        void bind() const override;
        void unbind() const override;

        inline GLuint getSize() const { return m_Size; }
    };
}}

#endif //CLIENT_VERTEXBUFFER_H
