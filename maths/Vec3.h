#ifndef CLIENT_VEC3_H
#define CLIENT_VEC3_H

#include <iostream>

struct Vec3 {

    float x, y, z;

    Vec3() = default;
    Vec3(const float&, const float&, const float&);

    Vec3& add(const Vec3& other);
    Vec3& subtract(const Vec3& other);
    Vec3& multiply(const Vec3& other);
    Vec3& divide(const Vec3& other);

    friend Vec3 operator+(Vec3, const Vec3&);
    friend Vec3 operator-(Vec3, const Vec3&);
    friend Vec3 operator*(Vec3, const Vec3&);
    friend Vec3 operator/(Vec3, const Vec3&);

    Vec3& operator+=(const Vec3&);
    Vec3& operator-=(const Vec3&);
    Vec3& operator*=(const Vec3&);
    Vec3& operator/=(const Vec3&);

    friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);
};


#endif //CLIENT_VEC3_H
