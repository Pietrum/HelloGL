#ifndef CLIENT_VEC2_H
#define CLIENT_VEC2_H

#include <iostream>

namespace maths {
    struct Vec2 {
        float x, y;

        Vec2() = default;
        Vec2(const float &x, const float &y);

        Vec2 &add(const Vec2 &other);
        Vec2 &subtract(const Vec2 &other);
        Vec2 &multiply(const Vec2 &other);
        Vec2 &divide(const Vec2 &other);

        friend Vec2 operator+(Vec2, const Vec2 &);
        friend Vec2 operator-(Vec2, const Vec2 &);
        friend Vec2 operator*(Vec2, const Vec2 &);
        friend Vec2 operator/(Vec2, const Vec2 &);

        Vec2 &operator+=(const Vec2 &);
        Vec2 &operator-=(const Vec2 &);
        Vec2 &operator*=(const Vec2 &);
        Vec2 &operator/=(const Vec2 &);

        friend std::ostream &operator<<(std::ostream &stream, const Vec2 &vector);
    };
}

#endif //CLIENT_VEC2_H
