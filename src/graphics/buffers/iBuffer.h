#ifndef CLIENT_IBUFFER_H
#define CLIENT_IBUFFER_H

#include <GL/glew.h>

#include "../../maths/Vec3.h"
#include "../../maths/Vec4.h"

#define BUFFER_MAX_SPRITES	60000
#define BUFFER_VERTEX_SIZE	sizeof(VertexData)
#define BUFFER_SPRITE_SIZE  (BUFFER_VERTEX_SIZE * 4)
#define BUFFER_MAX_SIZE	    (BUFFER_SPRITE_SIZE * BUFFER_MAX_SPRITES)
#define BUFFER_INDICES_SIZE (BUFFER_MAX_SPRITES * 6)

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX  1

namespace graphics { namespace buffers {
    struct VertexData
    {
        maths::Vec3 vertex;
        maths::Vec4 color;
    };

    class iBuffer {
    public:
        GLuint m_ID;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
    };
}}

#endif //CLIENT_IBUFFER_H
