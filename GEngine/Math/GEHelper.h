#ifndef GEHELPER_H
#define GEHELPER_H

#include <cmath>

#include "GEConstant.h"
#include "GEVector.h"

namespace ge {
    inline float degreesToRadians(float d) {
        return d * PI / 180.0f;
    }

    inline float radiansToDegrees(float r) {
        return r * 180.0f / PI;
    }

    template <typename T>
    inline T tMin(T a,T b) {
        return a < b ? a: b;
    }

    template <typename T>
    inline T tMin(T a, T b, T c) {
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }

    inline Vector3D tMin(const Vector3D& a, const Vector3D& b) {
        return Vector3D(tMin(a.x, b.x), tMin(a.y, b.y), tMin(a.z, b.z));
    }

    inline Vector3D tMin(const Vector3D& a, const Vector3D& b, const Vector3D& c) {
        return Vector3D(tMin(a.x, b.x, c.x), tMin(a.y, b.y, c.y), tMin(a.z, b.z, c.z));
    }

    template <typename T>
    inline T tMax(T a, T b) {
        return a > b ? a : b;
    }

    template <typename T>
    inline T tMax(T a, T b, T c) {
        return a > b ? (a > c ? a : c) : (b > c ? b : c);
    }

    inline Vector3D tMax(const Vector3D& a, const Vector3D& b) {
        return Vector3D(tMax(a.x, b.x), tMax(a.y, b.y), tMax(a.z, b.z));
    }

    inline Vector3D tMax(const Vector3D& a, const Vector3D& b, const Vector3D& c) {
        return Vector3D(tMax(a.x, b.x, c.x), tMax(a.y, b.y, c.y), tMax(a.z, b.z, c.z));
    }

    template <typename T>
    inline T tClamp(T val, T lo, T hi) {
        if (val < lo) return lo;
        if (val > hi) return hi;
        return val;
    }

    inline Vector3D tClamp(const Vector3D& val, const Vector3D& lo, const Vector3D& hi) {
        Vector3D clamp = tMin(val, hi);
        clamp = tMax(clamp, lo);
        return clamp;
    }

    inline bool isAabbOverlap(const Vector3D& min1, const Vector3D& max1, const Vector3D& min2, const Vector3D& max2) {
        return (
            min1.x <= min2.x && max1.x >= max2.x &&
            min1.y <= min2.y && max1.y >= max2.y &&
            min1.z <= min2.z && max1.z >= max2.z
        );
    }

    inline bool areFloatsSame(float f1, float f2) {
        return std::abs(f1 - f2) < FLOAT_TOL;
    }

}

#endif