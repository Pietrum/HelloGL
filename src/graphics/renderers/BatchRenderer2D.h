#ifndef CLIENT_BATCHRENDERER2D_H
#define CLIENT_BATCHRENDERER2D_H

#include "../buffers/VertexArray.h"
#include "../buffers/VertexBuffer.h"
#include "../buffers/IndexBuffer.h"
#include "iRenderer2D.h"

namespace graphics { namespace renderers {
        class BatchRenderer2D : public iRenderer2D {
        private:
            buffers::VertexArray *m_VAO;
            buffers::VertexBuffer *m_VBO;
            buffers::IndexBuffer *m_IBO;
            GLsizei m_IBC = 0;
            buffers::VertexData *m_Buffer;
        public:
            BatchRenderer2D();
            ~BatchRenderer2D();
            void submit(const Renderable2D*) override;
            void flush() override;
        };
    }}


#endif //CLIENT_BATCHRENDERER2D_H
