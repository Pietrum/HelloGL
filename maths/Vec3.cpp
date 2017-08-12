#include <iostream>

#include "Vec3.h"

Vec3::Vec3(const float& x, const float& y, const float& z)
        : x(x), y(y), z(z) {}

Vec3& Vec3::add(const Vec3& other) {
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vec3& Vec3::subtract(const Vec3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

Vec3& Vec3::multiply(const Vec3& other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;

    return *this;
}

Vec3& Vec3::divide(const Vec3& other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;

    return *this;
}

Vec3 operator+(Vec3 left, const Vec3& right) {
    return left.add(right);
}
Vec3 operator-(Vec3 left, const Vec3& right) {
    return left.subtract(right);
}
Vec3 operator*(Vec3 left, const Vec3& right) {
    return left.multiply(right);
}
Vec3 operator/(Vec3 left, const Vec3& right) {
    return left.divide(right);
}

Vec3& Vec3::operator+=(const Vec3& other) {
    return add(other);
}
Vec3& Vec3::operator-=(const Vec3& other) {
    return subtract(other);
}
Vec3& Vec3::operator*=(const Vec3& other) {
    return multiply(other);
}
Vec3& Vec3::operator/=(const Vec3& other) {
    return divide(other);
}

std::ostream& operator<<(std::ostream& stream, const Vec3& vector) {
    stream << "Vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";

    return stream;
}