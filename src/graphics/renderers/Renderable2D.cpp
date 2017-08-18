#include "Renderable2D.h"

namespace graphics { namespace renderers {
    Renderable2D::Renderable2D(maths::Vec2 size, maths::Vec3 position, maths::Vec4 color)
        : m_Color(color), m_Position(position), m_Size(size) {}
}}
