#include "GEEpaTriangle.h"
#include "GEEpaVertex.h"
#include "../../../../Math/GEVector.h"
#include "../../../../Math/GEHelper.h"

namespace ge {
    int EpaTriangle::count = 0;

    bool EpaTriangle::init(EpaVertex* v1, EpaVertex* v2, EpaVertex* v3, const Vector3D& center, bool check = false) {
        Vector3D v12 = v2->vertex - v1->vertex; // v1 -> v2
        Vector3D v13 = v3->vertex - v1->vertex; // v1 -> v3
        Vector3D vc1 = v1->vertex - center;    // center -> v1

        //whether vertices are CCW
        Vector3D vAxis = v12 ^ v13;  //v12 cross v13
        bool isInverted = false;
        float d = vc1 * vAxis;
        if (d < 0.0f) {
            if (check) {
                //Make vertices CCW
                auto tmp = v2;
                v2 = v3;
                v3 = tmp;
                vAxis *= -1;
            } else {
                isInverted = true;
            }
        }

        vertices[0] = *v1;
        vertices[1] = *v2;
        vertices[2] = *v3;
        normal = vAxis;
        Vector3D proj;
        projectingOrigin(v1->vertex, v2->vertex, v3->vertex, &proj);
        dist = proj.magnitudeWithoutSqrt();

        for (int i = 0; i < 3; ++i) {
            adjTriangle[i].remove();
            adjIndex[i] = -1;
        }
        return !isInverted;
    }
}