#ifndef GEHELPER_H
#define GEHELPER_H

#include "GEConstant.h"

namespace ge {
    inline float degreesToRadians(float d) {
        return d * PI / 180.0f;
    }

    inline float radiansToDegrees(float r) {
        return r * 180.0f / PI;
    }
}

#endif