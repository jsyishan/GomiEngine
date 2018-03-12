#ifndef GEBOXGEOMETRY_H
#define GEBOXGEOMETRY_H

#include "GEGeometry.h"
#include "../../Math/GEHelper.h"

class Vector3D;

namespace ge {

    //Axis Aligned Bounding Box
    class BoxGeometry : public Geometry {
    public:
        BoxGeometry(const Vector3D& hExtents);

        const Vector3D& getHalfExtents() const;
        void setHalfExtents(const Vector3D& hExtents);

    private:
        Vector3D halfExtents;
        Vector3D halfXAxis, halfYAxis, halfZAxis;

        void updateMass() override;
        void computeAabb(Aabb* aabb, const Transform& trans) const override;
        bool rayCast(const Vector3D& begin, const Vector3D& end, RaycastHit* hit) const override;
        void computeLocalSupportingVertex(const Vector3D& in, Vector3D* out) const override;
    };

    inline BoxGeometry::BoxGeometry(const Vector3D& hExtents) : Geometry(geometry_box) {
        halfExtents = hExtents;
        halfXAxis.set(hExtents.x, 0.0f, 0.0f);
        halfYAxis.set(0.0f, hExtents.y, 0.0f);
        halfZAxis.set(0.0f, 0.0f, hExtents.z);
        updateMass();

        float minHalfExtentsAxis = tMin(hExtents.x, hExtents.y, hExtents.z);
        if (gjkMargin > minHalfExtentsAxis * 0.2f) gjkMargin = minHalfExtentsAxis * 0.2f;
    }

    inline const Vector3D& BoxGeometry::getHalfExtents() const {
        return halfExtents;
    }

    inline void BoxGeometry::setHalfExtents(const Vector3D& hExtents) {
        halfExtents = hExtents;
    }
}

#endif