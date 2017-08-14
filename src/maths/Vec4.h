#ifndef CLIENT_VEC4_H
#define CLIENT_VEC4_H

#include <iostream>

namespace maths {
    struct Vec4 {
        float x, y, z, w;

        Vec4() = default;
        Vec4(const float &, const float &, const float &, const float &);

        Vec4 &add(const Vec4 &other);
        Vec4 &subtract(const Vec4 &other);
        Vec4 &multiply(const Vec4 &other);
        Vec4 &divide(const Vec4 &other);

        friend Vec4 operator+(Vec4, const Vec4 &);
        friend Vec4 operator-(Vec4, const Vec4 &);
        friend Vec4 operator*(Vec4, const Vec4 &);
        friend Vec4 operator/(Vec4, const Vec4 &);

        Vec4 &operator+=(const Vec4 &);
        Vec4 &operator-=(const Vec4 &);
        Vec4 &operator*=(const Vec4 &);
        Vec4 &operator/=(const Vec4 &);

        friend std::ostream &operator<<(std::ostream &stream, const Vec4 &vector);
    };
}

#endif //CLIENT_VEC4_H
