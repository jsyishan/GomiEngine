#ifndef GEQUATERNION_H
#define GEQUATERNION_H

#include <cmath>

#include "GEVector.h"

namespace ge {

    class Quaternion {
    public:
        float n;
        Vector v;

        Quaternion();
        Quaternion(float e0, float e1, float e2, float e3);
        Quaternion(float _n, const Vector& _v);
        Quaternion(const Vector& _v, float _n);

        Quaternion& operator+=(const Quaternion& q);
        Quaternion& operator-=(const Quaternion& q);
        Quaternion& operator*=(float s);
        Quaternion& operator/=(float s);
        Quaternion operator~() const;

        float magnitude();
        Vector getVector();
        float getScalar();
    };

    float getAngle(const Quaternion& q);
    Vector getAxis(const Quaternion& q);
    Quaternion rotate(const Quaternion& q1, const Quaternion& q2);
    Vector rotate(const Quaternion& q, const Vector& v);
    Vector rotate(const Vector& v, const Quaternion& q);
    Quaternion constructFromEulerAngles(float x, float y, float z);
    Vector getEulerAngles(const Quaternion& q);

    inline Quaternion::Quaternion() {
        n = 0.0f;
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
    }

    inline Quaternion::Quaternion(float e0, float e1, float e2, float e3) {
        n = e0;
        v.x = e1;
        v.y = e2;
        v.z = e3;
    }

    inline Quaternion::Quaternion(float _n, const Vector& _v) {
        n = _n;
        v.x = _v.x;
        v.y = _v.y;
        v.z = _v.z;
    }

    inline Quaternion::Quaternion(const Vector& _v, float _n) {
        n = _n;
        v.x = _v.x;
        v.y = _v.y;
        v.z = _v.z;
    }

    inline Quaternion& Quaternion::operator+=(const Quaternion& q) {
        n += q.n;
        v.x += q.v.x;
        v.y += q.v.y;
        v.z += q.v.z;
        return *this;
    }

    inline Quaternion& Quaternion::operator-=(const Quaternion& q) {
        n -= q.n;
        v.x -= q.v.x;
        v.y -= q.v.y;
        v.z -= q.v.z;
        return *this;
    }

    inline Quaternion& Quaternion::operator*=(float s) {
        n *= s;
        v.x *= s;
        v.y *= s;
        v.z *= s;
        return *this;
    }

    inline Quaternion& Quaternion::operator/=(float s) {
        n /= s;
        v.x /= s;
        v.y /= s;
        v.z /= s;
        return *this;
    }

    inline Quaternion Quaternion::operator~() const {
        return Quaternion(
            n, -v.x, -v.y, -v.z
        );
    }

    inline float Quaternion::magnitude() {
        return (float) std::sqrt(n * n + v.x * v.x + v.y * v.y + v.z * v.z);
    }

    inline Vector Quaternion::getVector() {
        return v;
    }

    inline float Quaternion::getScalar() {
        return n;
    }

    inline Quaternion operator+(const Quaternion& q1, const Quaternion& q2) {
        return Quaternion(q1.n + q2.n, q1.v.x + q2.v.x, q1.v.y + q2.v.y, q1.v.z + q2.v.z);
    }

    inline Quaternion operator-(const Quaternion& q1, const Quaternion& q2) {
        return Quaternion(q1.n - q2.n, q1.v.x - q2.v.x, q1.v.y - q2.v.y, q1.v.z - q2.v.z);
    }

    inline Quaternion operator*(const Quaternion& q1, const Quaternion& q2) {
        float n = q1.n * q2.n - q1.v * q2.v;
        Vector v = q1.n * q2.v + q2.n * q1.v + q1.v ^ q2.v;
        return Quaternion(n, v.x, v.y, v.z);
    }

    inline Quaternion operator*(const Quaternion& q, float s) {
        return Quaternion(q.n * s, q.v.x * s, q.v.y * s, q.v.z * s);
    }

    inline Quaternion operator*(float s, const Quaternion& q) {
        return Quaternion(q.n * s, q.v.x * s, q.v.y * s, q.v.z * s);
    }

    inline Quaternion operator*(const Quaternion& q, const Vector& v) {
        return (q * Quaternion(0.0f, v.x, v.y, v.z));
    }

    inline Quaternion operator*(const Vector& v, const Quaternion& q) {
        return (q * Quaternion(0.0f, v.x, v.y, v.z));
    }

    inline Quaternion operator/(const Quaternion& q, float s) {
        return Quaternion(q.n / s, q.v.x / s, q.v.y / s, q.v.z / s);
    }

}

#endif