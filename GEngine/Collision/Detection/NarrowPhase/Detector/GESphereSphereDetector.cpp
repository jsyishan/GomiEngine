#include "GESphereSphereDetector.h"

#include <cmath>

#include "../../../Geometry/GESphereGeometry.h"
#include "../../../../Math/GEVector.h"

namespace ge {
    void SphereSphereDetector::detectImpl(DetectorResult* result, Geometry* geo1, Geometry* geo2, const Transform& trans1, const Transform& trans2, CacheDetectorData* data) {
        SphereGeometry* sphere1 = dynamic_cast<SphereGeometry*>(geo1);
        SphereGeometry* sphere2 = dynamic_cast<SphereGeometry*>(geo2);

        result->incremental = false;

        Vector3D offset = trans1.position - trans2.position;
        Vector3D n;
        float r1 = sphere1->getRadius();
        float r2 = sphere2->getRadius();

        float tmp = offset * offset;
        if (tmp >= (r1 + r2) * (r1 + r2)) return;

        float len = std::sqrt(tmp);
        if (len > 0) n = (1 / len) * offset;
        else n.set(1.0f, 0.0f, 0.0f);
        setNormal(result, n);

        Vector3D pos1 = n * -r1 + trans1.position;
        Vector3D pos2 = n * r2 + trans2.position;
        addPoint(result, pos1, pos2, r1 + r2 - len, 0);
    }
}