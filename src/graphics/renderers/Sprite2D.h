#ifndef CLIENT_SPRITE2D_H
#define CLIENT_SPRITE2D_H

#include "Renderable2D.h"

namespace graphics { namespace renderers {
    class Sprite2D : public Renderable2D {
    public:
        Sprite2D(float, float, float, float, const maths::Vec4& color);
    };
}}

#endif //CLIENT_SPRITE2D_H
