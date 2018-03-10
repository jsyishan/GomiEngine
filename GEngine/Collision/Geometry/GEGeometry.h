#ifndef GEGEOMETRY_H
#define GEGEOMETRY_H

#include "GEAabb.h"

namespace ge {
    class Geometry {
    public:
        //Type of Geometry
        enum Type {
            geometry_box = 0,
            geometry_sphere = 1,
            geometry_cylinder = 2,
            geometry_cone = 3,
            geometry_capsule = 4,
            geometry_convex_hull = 5
        };

        virtual ~Geometry() = 0;

    private:
        Type type;
        float volume;

        Geometry(Type type);
        virtual void updateMass() = 0;
        virtual void computeAabb()

    };
}
#endif // !GEGEOMETRY_H
