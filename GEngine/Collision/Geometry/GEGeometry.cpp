#include "GEGeometry.h"

namespace ge {
    bool Geometry::rayCast(const Vector3D& begin, const Vector3D& end, const Transform& trans, RaycastHit* hit) const {
        //local Vector of begin and end
        Vector3D loc_begin, loc_end;

        loc_begin = begin - trans.position;
        loc_end = end - trans.position;

        loc_begin = loc_begin * trans.rotation;
        loc_end = loc_end * trans.rotation;

        if (rayCast(loc_begin, loc_end, hit)) {
            Vector3D loc_position = hit->position * trans.rotation;
            loc_position += trans.position;
            Vector3D loc_normal = hit->normal * trans.rotation;

            hit->position = loc_position;
            hit->normal = loc_normal;
            return true;
        }
        return false;
    }
}