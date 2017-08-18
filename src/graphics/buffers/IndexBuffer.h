#ifndef CLIENT_INDEXBUFFER_H
#define CLIENT_INDEXBUFFER_H

#include "iBuffer.h"

namespace graphics { namespace buffers {
    class IndexBuffer : public iBuffer {
    public:
        IndexBuffer();
        IndexBuffer(GLuint*, GLsizei);
        IndexBuffer(GLushort *, GLsizei);
        ~IndexBuffer();

        void bind() const override;
        void unbind() const override;
    };
}}

#endif //CLIENT_INDEXBUFFER_H
