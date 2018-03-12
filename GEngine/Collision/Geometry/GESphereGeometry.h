#ifndef GESPHEREGEOMETRY_H
#define GESPHEREGEOMETRY_H

#include "GEGeometry.h"

namespace ge {
    class SphereGeometry : public Geometry {
    public:
        SphereGeometry(float r);

        Geometry* clone(SmallObjectAllocator* allocator) const override;
        void computeLocalSupportingVertex(const Vector3D& in, Vector3D* out) const override;
        float getRadius() const;

    private:
        float radius;

        void updateMass() override;
        void computeAabb(Aabb* aabb, const Transform& trans) const override;
        bool rayCast(const Vector3D& begin, const Vector3D& end, RaycastHit* hit) const override;
    };

    inline SphereGeometry::SphereGeometry(float r) : Geometry(geometry_sphere) {
        radius = r;
        gjkMargin = r;
        updateMass();
    }

    inline float SphereGeometry::getRadius() const {
        return radius;
    }
}


#endif