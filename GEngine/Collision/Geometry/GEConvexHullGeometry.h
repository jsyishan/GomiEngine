#ifndef GECONVEXHULLGEOMETRY_H
#define GECONVEXHULLGEOMETRY_H

#include "GEGeometry.h"
#include "../../Math/GEVector.h"

namespace ge {
    class ConvexHullGeometry : public Geometry {
    public:
        ConvexHullGeometry(const Vector3D* vs, int sz);
        
        Geometry* clone(SmallObjectAllocator* allocator) const override;
        const Vector3D* getVertices() const;
        
    private:
        Vector3D* vertices;
        int size;
        Vector3D* tmpVertices;

        void updateMass() override;
        void computeAabb(Aabb* aabb, const Transform& trans) const override;
        bool rayCast(const Vector3D& begin, const Vector3D& end, RaycastHit* hit) const override;
        void computeLocalSupportingVertex(const Vector3D& in, Vector3D* out) const override;
    };

    inline ConvexHullGeometry::ConvexHullGeometry(const Vector3D* vs, int sz) : Geometry(geometry_convex_hull) {
        size = sz;

        vertices = new Vector3D[sz];
        tmpVertices = new Vector3D[sz];
        for (int i = 0; i < sz; ++i) {
            vertices[i] = vs[i];
            tmpVertices[i] = vs[i];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        }

        isUseGjkRayCast = true;
        updateMass();
    }

    inline const Vector3D* ConvexHullGeometry::getVertices() const {
        return vertices;
    }


}

#endif