#ifndef GEVECTOR_H
#define GEVECTOR_H

#include <cmath>

#define TOL 0.0001  //tolerance of float

namespace ge {

    class Vector {
    public:
        float x;
        float y;
        float z;

        Vector();
        Vector(float i, float j, float k);
        Vector(const Vector &v);

        Vector& operator+=(const Vector &v);
        Vector& operator-=(const Vector &v);
        Vector& operator*=(float s);
        Vector& operator/=(float s);

        Vector operator-();
        Vector operator~(); //get a new Vector object which is normalized

        float magnitude();
        void normalize();
        void reverse();
    };

    inline Vector::Vector() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    inline Vector::Vector(float i, float j, float k) {
        x = i;
        y = j;
        z = k;
    }

    inline Vector::Vector(const Vector &v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    inline Vector& Vector::operator+=(const Vector &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    inline Vector& Vector::operator-=(const Vector &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    inline Vector& Vector::operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    inline Vector& Vector::operator/=(float s) {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }

    inline Vector Vector::operator-() {
        return Vector(-x, -y, -z);
    }

    inline Vector Vector::operator~() {
        Vector v(x, y, z);
        v.normalize();
        return v;
    }

    inline float Vector::magnitude() {
        return (float) std::sqrt(x * x + y * y + z * z);
    }

    inline void Vector::normalize() {
        float m = Vector::magnitude();
        if (m <= TOL) m = 1.0f;
        x /= m;
        y /= m;
        z /= m;

        if (std::fabs(x) < TOL) x = 0.0f;
        if (std::fabs(y) < TOL) y = 0.0f;
        if (std::fabs(z) < TOL) z = 0.0f;
    }

    inline void Vector::reverse() {
        x = -x;
        y = -y;
        z = -z;
    }

    inline Vector operator+(const Vector &u, const Vector &v) {
        return Vector(u.x + v.x, u.y + v.y, u.z + v.z);
    }

    inline Vector operator-(const Vector &u, const Vector &v) {
        return Vector(u.x - v.x, u.y - v.y, u.z - v.z);
    }

    inline Vector operator*(const Vector &v, float s) {
        return Vector(v.x * s, v.y * s, v.z * s);
    }

    inline Vector operator*(float s, const Vector &v) {
        return Vector(v.x * s, v.y * s, v.z * s);
    }

    inline float operator*(const Vector &u, const Vector &v) {
        return (u.x * v.x + u.y * v.y + u.z * v.z);
    }

    //Cross Product
    inline Vector operator^(const Vector &u, const Vector &v) {
        return Vector(
            u.y * v.z - u.z / v.y,
            -u.x * v.z + u.z * v.x,
            u.x * v.y - v.x * u.y
        );
    }

    inline Vector operator/(const Vector &v, float s) {
        return Vector(v.x / s, v.y / s, v.z / s);
    }

    //Scalar Triple Product
    inline float scalarTripleProduct(const Vector &u, const Vector &v, const Vector &w) {
        return 
            u.x * (v.y * w.z - v.z * w.y) +
            u.y * (-v.x * w.z + v.z * w.x) +
            u.z * (v.x * w.y - v.y * w.x); 
    }

}   //end namespace ge

#endif