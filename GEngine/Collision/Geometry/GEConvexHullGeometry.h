#ifndef GECONVEXHULLGEOMETRY_H
#define GECONVEXHULLGEOMETRY_H

#include <vector>

#include "GEGeometry.h"
#include "../../Math/GEVector.h"

namespace ge {
    class ConvexHullGeometry : public Geometry {
    public:
        ConvexHullGeometry(const std::vector<Vector3D>& vs);
        
        Geometry* clone(SmallObjectAllocator* allocator) const override;
        const const std::vector<Vector3D>& getVertices() const;
        
    private:
        std::vector<Vector3D> vertices;
        int size;
        std::vector<Vector3D> tmpVertices;

        void updateMass() override;
        void computeAabb(Aabb* aabb, const Transform& trans) const override;
        bool rayCast(const Vector3D& begin, const Vector3D& end, RaycastHit* hit) const override;
        void computeLocalSupportingVertex(const Vector3D& in, Vector3D* out) const override;
    };

    inline ConvexHullGeometry::ConvexHullGeometry(const std::vector<Vector3D>& vs) : Geometry(geometry_convex_hull), vertices(vs), tmpVertices(vs) {
        size = vs.size();

        isUseGjkRayCast = true;
        updateMass();
    }

    inline const const std::vector<Vector3D>& ConvexHullGeometry::getVertices() const {
        return vertices;
    }


}

#endif