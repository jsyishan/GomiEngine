#include <cmath>
#include <new>

#include "GESphereGeometry.h"
#include "../../Math/GEConstant.h"
#include "../../Math/GEMatrix33.h"
#include "../../Math/GEVector.h"

namespace ge {
    Geometry* SphereGeometry::clone(SmallObjectAllocator* allocator) const {
        void* mem = allocator->allocate(sizeof(SphereGeometry));
        SphereGeometry* clone = new (mem) SphereGeometry(radius);
        *clone = *this;
        return clone;
    }

    void SphereGeometry::updateMass() {
        volume = 4 / 3 * PI * radius * radius * radius;
        inertiaCoeff = Matrix33().diagonal(2 / 5 * radius * radius, 2 / 5 * radius * radius, 2 / 5 * radius * radius);
    }

    void SphereGeometry::computeAabb(Aabb* aabb, const Transform& trans) const {
        Vector3D rad(radius, radius, radius);
        aabb->setMin(trans.position - rad);
        aabb->setMax(trans.position + rad);
    }

    void SphereGeometry::computeLocalSupportingVertex(const Vector3D& in, Vector3D* out) const {
        out->zero();
    }

    bool SphereGeometry::rayCast(const Vector3D& begin, const Vector3D& end, RaycastHit* hit) const {
        Vector3D offset = end - begin;

        float x = offset * offset;
        float y = begin * offset;
        float z = begin * begin - radius * radius;
        
        float w = y * y - x * z;
        if (w < 0) return false;

        float t = (-y - std::sqrt(w)) / x;
        if (t < 0 || t > 1) return false;

        Vector3D loc_position, loc_normal;
        loc_position = begin + offset * t;
        loc_normal = Vector3D(loc_position).normalize();

        hit->position = loc_position;
        hit->normal = loc_normal;
        hit->fraction = t;
        return true;
    }
}