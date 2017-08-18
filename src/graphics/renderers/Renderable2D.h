#ifndef CLIENT_RENDERABLE2D_H
#define CLIENT_RENDERABLE2D_H

#include "../../maths/Vec2.h"
#include "../../maths/Vec3.h"
#include "../../maths/Vec4.h"

namespace graphics { namespace renderers {
    class Renderable2D {
    protected:
        maths::Vec4 m_Color;
        maths::Vec3 m_Position;
        maths::Vec2 m_Size;

    public:
        Renderable2D(maths::Vec2, maths::Vec3, maths::Vec4);
        ~Renderable2D() = default;

        inline const maths::Vec4& getColor() const { return m_Color; };
        inline const maths::Vec3& getPosition() const { return m_Position; };
        inline const maths::Vec2& getSize() const { return m_Size; };
    };
}}


#endif //CLIENT_RENDERABLE2D_H
