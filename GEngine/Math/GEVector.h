#ifndef GEVECTOR_H
#define GEVECTOR_H

#include <cmath>

#include "GEConstant.h"

namespace ge {

    class Vector2D {
    public:
        static Vector2D vec2_zero;
        float x;
        float y;

        Vector2D();
        Vector2D(float i, float j);
        Vector2D(const Vector2D& v2);

        Vector2D& operator+=(const Vector2D& v2);
        Vector2D& operator-=(const Vector2D& v2);
        Vector2D& operator*=(float s);
        Vector2D& operator/=(float s);

        Vector2D operator-();
        Vector2D operator~(); //get a new Vector3D object which is normalized

        float magnitude() const;
        float magnitudeWithoutSqrt() const;
        Vector2D& normalize();
        Vector2D& reverse();
        Vector2D& zero();
        Vector2D& abs();
        Vector2D& set(float a, float b);
    };

    class Vector3D {
    public:
        static Vector3D vec3_zero;
        float x;
        float y;
        float z;

        Vector3D();
        Vector3D(float i, float j, float k);
        Vector3D(const Vector3D& v);
        Vector3D(const Vector2D& v2);
        Vector3D(const Vector2D& v2, float k);
        Vector3D(float k, const Vector2D& v2);

        Vector3D& operator+=(const Vector3D& v);
        Vector3D& operator-=(const Vector3D& v);
        Vector3D& operator*=(float s);
        Vector3D& operator/=(float s);

        bool operator==(const Vector3D& v);
        bool operator!=(const Vector3D& v);

        Vector3D operator-();
        Vector3D operator~(); //get a new Vector3D object which is normalized

        float magnitude() const;
        float magnitudeWithoutSqrt() const;
        Vector3D& normalize();
        Vector3D& reverse();
        Vector3D& zero();
        Vector3D& abs();
        Vector3D& set(float a, float b, float c);
        Vector3D& set(const Vector3D& v);
    };

    /*
    * Functions of Class Vector3D
    *
    */

    inline Vector3D::Vector3D() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    inline Vector3D::Vector3D(float i, float j, float k) {
        x = i;
        y = j;
        z = k;
    }

    inline Vector3D::Vector3D(const Vector3D &v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    inline Vector3D::Vector3D(const Vector2D &v2) {
        x = v2.x;
        y = v2.y;
        z = 0.0f;
    }

    inline Vector3D::Vector3D(const Vector2D &v2, float k) {
        x = v2.x;
        y = v2.y;
        z = k;
    }

    inline Vector3D::Vector3D(float k, const Vector2D &v2) {
        x = v2.x;
        y = v2.y;
        z = k;
    }

    inline Vector3D& Vector3D::operator+=(const Vector3D &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    inline Vector3D& Vector3D::operator-=(const Vector3D &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    inline Vector3D& Vector3D::operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    inline Vector3D& Vector3D::operator/=(float s) {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }

    inline bool Vector3D::operator==(const Vector3D& v) {
        return (x == v.x && y == v.y && z == v.z);
    }

    inline bool Vector3D::operator!=(const Vector3D& v) {
        return (x != v.x || y != v.y || z != v.z);
    }

    inline Vector3D Vector3D::operator-() {
        return Vector3D(-x, -y, -z);
    }

    inline Vector3D Vector3D::operator~() {
        Vector3D v(x, y, z);
        v.normalize();
        return v;
    }

    inline float Vector3D::magnitude() const {
        return (float) std::sqrt(x * x + y * y + z * z);
    }

    inline float Vector3D::magnitudeWithoutSqrt() const {
        return  x * x + y * y + z * z;
    }

    inline Vector3D& Vector3D::normalize() {
        float m = Vector3D::magnitude();
        if (m <= FLOAT_TOL) m = 1.0f;
        x /= m;
        y /= m;
        z /= m;

        if (std::fabs(x) < FLOAT_TOL) x = 0.0f;
        if (std::fabs(y) < FLOAT_TOL) y = 0.0f;
        if (std::fabs(z) < FLOAT_TOL) z = 0.0f;
        
        return *this;
    }

    inline Vector3D& Vector3D::reverse() {
        x = -x;
        y = -y;
        z = -z;

        return *this;
    }

    inline Vector3D& Vector3D::zero() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;

        return *this;
    }

    inline Vector3D& Vector3D::abs() {
        x = x > 0.0f ? x : -x;
        y = y > 0.0f ? y : -y;
        z = z > 0.0f ? z : -z;
        
        return *this;
    }

    inline Vector3D& Vector3D::set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;

        return *this;
    }

    inline Vector3D& Vector3D::set(const Vector3D& v) {
        x = v.x;
        y = v.y;
        z = v.z;

        return *this;
    }

    /*
    * Functions of Class Vector2D
    *
    */

    inline Vector2D::Vector2D() {
        x = 0.0f;
        y = 0.0f;
    }

    inline Vector2D::Vector2D(float i, float j) {
        x = i;
        y = j;
    }

    inline Vector2D::Vector2D(const Vector2D &v) {
        x = v.x;
        y = v.y;
    }

    inline Vector2D& Vector2D::operator+=(const Vector2D &v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    inline Vector2D& Vector2D::operator-=(const Vector2D &v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    inline Vector2D& Vector2D::operator*=(float s) {
        x *= s;
        y *= s;
        return *this;
    }

    inline Vector2D& Vector2D::operator/=(float s) {
        x /= s;
        y /= s;
        return *this;
    }

    inline Vector2D Vector2D::operator-() {
        return Vector2D(-x, -y);
    }

    inline Vector2D Vector2D::operator~() {
        Vector2D v(x, y);
        v.normalize();
        return v;
    }

    inline float Vector2D::magnitude() const {
        return (float) std::sqrt(x * x + y * y);
    }

    inline float Vector2D::magnitudeWithoutSqrt() const {
        return x * x + y * y;
    }

    inline Vector2D& Vector2D::normalize() {
        float m = Vector2D::magnitude();
        if (m <= FLOAT_TOL) m = 1.0f;
        x /= m;
        y /= m;

        if (std::fabs(x) < FLOAT_TOL) x = 0.0f;
        if (std::fabs(y) < FLOAT_TOL) y = 0.0f;
        
        return *this;
    }

    inline Vector2D& Vector2D::reverse() {
        x = -x;
        y = -y;

        return *this;
    }

    inline Vector2D& Vector2D::zero() {
        x = 0.0f;
        y = 0.0f;

        return *this;
    }

    inline Vector2D& Vector2D::abs() {
        x = x > 0.0f ? x : -x;
        y = y > 0.0f ? y : -y;
        
        return *this;
    }

    inline Vector2D& Vector2D::set(float a, float b) {
        x = a;
        y = b;
        
        return *this;
    }

    //plus operator
    inline Vector3D operator+(const Vector3D &u, const Vector3D &v) {
        return Vector3D(u.x + v.x, u.y + v.y, u.z + v.z);
    }
    
    inline Vector2D operator+(const Vector2D &u, const Vector2D &v) {
        return Vector2D(u.x + v.x, u.y + v.y);
    }

    //minus operator
    inline Vector3D operator-(const Vector3D &u, const Vector3D &v) {
        return Vector3D(u.x - v.x, u.y - v.y, u.z - v.z);
    }

    inline Vector2D operator-(const Vector2D &u, const Vector2D &v) {
        return Vector2D(u.x - v.x, u.y - v.y);
    }

    //multiply operator between Vector and float
    inline Vector3D operator*(const Vector3D &v, float s) {
        return Vector3D(v.x * s, v.y * s, v.z * s);
    }

    inline Vector3D operator*(float s, const Vector3D &v) {
        return Vector3D(v.x * s, v.y * s, v.z * s);
    }

    inline Vector2D operator*(const Vector2D &v, float s) {
        return Vector2D(v.x * s, v.y * s);
    }

    inline Vector2D operator*(float s, const Vector2D &v) {
        return Vector2D(v.x * s, v.y * s);
    }

    //multiply operator between two Vector
    inline float operator*(const Vector3D &u, const Vector3D &v) {
        return (u.x * v.x + u.y * v.y + u.z * v.z);
    }

    inline float operator*(const Vector2D &u, const Vector2D &v) {
        return (u.x * v.x + u.y * v.y );
    }

    //Cross Product
    inline Vector3D operator^(const Vector3D &u, const Vector3D &v) {
        return Vector3D(
            u.y * v.z - u.z / v.y,
            -u.x * v.z + u.z * v.x,
            u.x * v.y - v.x * u.y
        );
    }

    inline Vector3D operator^(const Vector2D &v, float s) {
        return Vector2D(-s * v.y, s * v.x);
    }

    inline Vector3D operator^(float s, const Vector2D &v) {
        return Vector2D(-s * v.y, s * v.x);
    }

    inline Vector3D operator/(const Vector3D &v, float s) {
        return Vector3D(v.x / s, v.y / s, v.z / s);
    }

    inline Vector2D operator/(const Vector2D &v, float s) {
        return Vector2D(v.x / s, v.y / s);
    }

    //Scalar Triple Product
    inline float scalarTripleProduct(const Vector3D &u, const Vector3D &v, const Vector3D &w) {
        return 
            u.x * (v.y * w.z - v.z * w.y) +
            u.y * (-v.x * w.z + v.z * w.x) +
            u.z * (v.x * w.y - v.y * w.x); 
    }

}   //end namespace ge

#endif