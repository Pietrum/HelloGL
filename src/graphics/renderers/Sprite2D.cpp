#include "Sprite2D.h"

namespace graphics { namespace renderers {
    Sprite2D::Sprite2D(float w, float h, float x, float y, const maths::Vec4& color)
        : Renderable2D(maths::Vec2(w, h), maths::Vec3(x, y, 0), color) {}
}}