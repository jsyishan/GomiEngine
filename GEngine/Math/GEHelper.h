#ifndef GEHELPER_H
#define GEHELPER_H

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
}

#endif