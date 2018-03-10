#ifndef GERAYCASTHIT_H
#define GERAYCASTHIT_H

#include "../../Math/GEVector.h"

namespace ge {
    class RaycastHit {
    public:
        Vector3D position;
        Vector3D normal;

        float fraction;

        RaycastHit();
    };

    RaycastHit::RaycastHit() {
        position = Vector3D::vec3_zero;
        normal = Vector3D::vec3_zero;
        fraction = 0.0f;
    }
}

#endif // !GERAYCASTHIT_H