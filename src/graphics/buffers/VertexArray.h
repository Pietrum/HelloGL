#ifndef CLIENT_VERTEXARRAY_H
#define CLIENT_VERTEXARRAY_H

#include <vector>
#include "VertexBuffer.h"

namespace graphics { namespace buffers {
    class VertexArray : public iBuffer {
        std::vector<VertexBuffer *> m_Buffers;
    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(VertexBuffer*, GLuint);
        void addAttrib(GLuint, GLuint, GLuint);
        void bind() const override;
        void unbind() const override;
    };
}}

#endif //CLIENT_VERTEXARRAY_H
