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
    inline T min(T a,T b) {
        return a < b ? a: b;
    }

    inline Vector3D min(const Vector3D& a, const Vector3D& b) {
        return Vector3D(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
    }

    template <typename T>
    inline T max(T a, T b) {
        return a < b ? b : a;
    }

    inline Vector3D max(const Vector3D& a, const Vector3D& b) {
        return Vector3D(max(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
    }
}

#endif