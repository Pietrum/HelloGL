#ifndef CLIENT_RENDERER_H
#define CLIENT_RENDERER_H

#include <deque>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderable2D.h"
#include "Sprite2D.h"

namespace graphics { namespace renderers {
    class iRenderer2D {
    protected:
        std::deque<const Sprite2D*> m_Queue;
    public:
        virtual void submit(const Renderable2D*) = 0;
        virtual void flush() = 0;
    };
}}

#endif //CLIENT_RENDERER_H
