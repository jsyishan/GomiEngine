#ifndef GEMATRIX33_H
#define GEMATRIX33_H

#include <cmath>

#include "GEConstant.h"
#include "GEVector.h"

namespace ge {

    class Matrix33 {
    public:
        float e11, e12, e13,
              e21, e22, e23,
              e31, e32, e33;
        
        Matrix33();
        Matrix33(float a11, float a12, float a13,
                 float a21, float a22, float a23,
                 float a31, float a32, float a33);
        Matrix33(float m[3][3]);
        
        Matrix33& operator+=(const Matrix33& m);
        Matrix33& operator-=(const Matrix33& m);
        Matrix33& operator*=(float s);
        Matrix33& operator/=(float s);
        
        float det();
        Matrix33 transpose();
        Matrix33 inverse();
    };

    inline Matrix33::Matrix33() {
        e11 = e12 = e13 = 0.0f;
        e21 = e22 = e23 = 0.0f;
        e31 = e32 = e33 = 0.0f;
    }

    inline Matrix33::Matrix33(
        float a11, float a12, float a13,
        float a21, float a22, float a23,
        float a31, float a32, float a33) {
            e11 = a11;  e12 = a12;  e13 = a13;
            e21 = a21;  e22 = a22;  e23 = a23;
            e31 = a31;  e32 = a32;  e33 = a33;
    }

    inline Matrix33::Matrix33(float m[3][3]) {
        e11 = m[0][0];  e12 = m[0][1];  e13 = m[0][2];
        e21 = m[1][0];  e22 = m[1][1];  e23 = m[1][2];
        e31 = m[2][0];  e32 = m[2][1];  e33 = m[2][2];
    }

    inline Matrix33& Matrix33::operator+=(const Matrix33& m) {
        e11 += m.e11;   e12 += m.e12;   e13 += m.e13;
        e21 += m.e21;   e22 += m.e22;   e23 += m.e23;
        e31 += m.e31;   e32 += m.e32;   e33 += m.e33;
        return *this;
    }

    inline Matrix33& Matrix33::operator-=(const Matrix33& m) {
        e11 -= m.e11;   e12 -= m.e12;   e13 -= m.e13;
        e21 -= m.e21;   e22 -= m.e22;   e23 -= m.e23;
        e31 -= m.e31;   e32 -= m.e32;   e33 -= m.e33;
        return *this;
    }

    inline Matrix33& Matrix33::operator*=(float s) {
        e11 *= s;   e12 *= s;   e13 *= s;
        e21 *= s;   e22 *= s;   e23 *= s;
        e31 *= s;   e32 *= s;   e33 *= s;
        return *this;
    }

    inline Matrix33& Matrix33::operator/=(float s) {
        e11 /= s;   e12 /= s;   e13 /= s;
        e21 /= s;   e22 /= s;   e23 /= s;
        e31 /= s;   e32 /= s;   e33 /= s;
        return *this;
    }

    inline float Matrix33::det() {
        return (
            e11 * e22 * e33 -
            e11 * e32 * e12 +
            e21 * e32 * e13 -
            e21 * e12 * e33 +
            e31 * e12 * e23 -
            e31 * e22 * e13 );
    }

    inline Matrix33 Matrix33::transpose() {
        return Matrix33(
            e11, e21, e31,
            e12, e22, e32,
            e13, e23, e33
        );
    }

    inline Matrix33 Matrix33::inverse() {
        float d = Matrix33::det();
        if (d <= FLOAT_TOL) d = 1.0f;

        return Matrix33(
            (e22 * e33 - e23 * e32) / d, -(e12 * e33 - e13 * e32) / d, (e12 * e23 - e13 * e22) / d,
            -(e21 * e33 - e23 * e31) / d, (e11 * e33 - e13 * e31) / d, -(e11 * e23 - e13 * e21) / d,
            (e21 * e32 - e22 * e31) / d, -(e11 * e32 - e12 * e31) / d, (e11 * e22 - e12 * e21) / d
        );
    }

    inline Matrix33 operator+(const Matrix33& m1, const Matrix33& m2) {
        return Matrix33(
            m1.e11 + m2.e11, m1.e12 + m2.e12, m1.e13 + m2.e13,
            m1.e21 + m2.e21, m1.e22 + m2.e22, m1.e23 + m2.e23,
            m1.e31 + m2.e31, m1.e32 + m2.e32, m1.e33 + m2.e33
        );
    }

    inline Matrix33 operator-(const Matrix33& m1, const Matrix33& m2) {
        return Matrix33(
            m1.e11 - m2.e11, m1.e12 - m2.e12, m1.e13 - m2.e13,
            m1.e21 - m2.e21, m1.e22 - m2.e22, m1.e23 - m2.e23,
            m1.e31 - m2.e31, m1.e32 - m2.e32, m1.e33 - m2.e33
        );
    }

    inline Matrix33 operator*(const Matrix33& m1, const Matrix33& m2) {
        return Matrix33(
            m1.e11 * m2.e11 + m1.e12 * m2.e21 + m1.e13 * m2.e31,
            m1.e11 * m2.e12 + m1.e12 * m2.e22 + m1.e13 * m2.e32,
            m1.e11 * m2.e13 + m1.e12 * m2.e23 + m1.e13 * m2.e33,
            m1.e21 * m2.e11 + m1.e22 * m2.e21 + m1.e23 * m2.e31,
            m1.e21 * m2.e12 + m1.e22 * m2.e22 + m1.e23 * m2.e32,
            m1.e21 * m2.e13 + m1.e22 * m2.e23 + m1.e23 * m2.e33,
            m1.e31 * m2.e11 + m1.e32 * m2.e21 + m1.e33 * m2.e31,
            m1.e31 * m2.e12 + m1.e32 * m2.e22 + m1.e33 * m2.e32,
            m1.e31 * m2.e13 + m1.e32 * m2.e23 + m1.e33 * m2.e33
        );
    }

    inline Matrix33 operator*(const Matrix33& m, float s) {
        return Matrix33(
            m.e11 * s, m.e12 * s, m.e13 * s,
            m.e21 * s, m.e22 * s, m.e23 * s,
            m.e31 * s, m.e32 * s, m.e33 * s
        );
    }

    inline Matrix33 operator*(float s, const Matrix33& m) {
        return Matrix33(
            m.e11 * s, m.e12 * s, m.e13 * s,
            m.e21 * s, m.e22 * s, m.e23 * s,
            m.e31 * s, m.e32 * s, m.e33 * s
        );
    }

    inline Vector operator*(const Matrix33& m, const Vector& v) {
        return Vector(
            m.e11 * v.x + m.e12 * v.y + m.e13 * v.z,
            m.e21 * v.x + m.e22 * v.y + m.e23 * v.z,
            m.e31 * v.x + m.e32 * v.y + m.e33 * v.z
        );
    }

    inline Vector operator*(const Vector& v, const Matrix33& m) {
        return Vector(
            m.e11 * v.x + m.e12 * v.y + m.e13 * v.z,
            m.e21 * v.x + m.e22 * v.y + m.e23 * v.z,
            m.e31 * v.x + m.e32 * v.y + m.e33 * v.z
        );
    }

    inline Matrix33 operator/(const Matrix33& m, float s) {
        return Matrix33(
            m.e11 / s, m.e12 / s, m.e13 / s,
            m.e21 / s, m.e22 / s, m.e23 / s,
            m.e31 / s, m.e32 / s, m.e33 / s
        );
    }

}   //end namespace ge

#endif