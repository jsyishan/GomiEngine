#include <cmath>
#include <new>

#include "GEBoxGeometry.h"

#include "../../Math/GEVector.h"
#include "../../Math/GEMatrix33.h"
#include "../../Math/GEHelper.h"
#include "../../Math/GEConstant.h"

namespace ge {

    Geometry* BoxGeometry::clone(SmallObjectAllocator* allocator) const {
        void* mem = allocator->allocate(sizeof(BoxGeometry));
        BoxGeometry* clone = new (mem) BoxGeometry(halfExtents);
        *clone = *this;
        return clone;
    }

    void BoxGeometry::updateMass() {
        volume = halfExtents.x * halfExtents.y * halfExtents.z * 8.0f;

        Vector3D sq(halfExtents.x * halfExtents.x, halfExtents.y * halfExtents.y, halfExtents.z * halfExtents.z);
        inertiaCoeff = Matrix33().diagonal(1.0f / 3 * (sq.y + sq.z), 1.0f / 3 * (sq.x + sq.z), 1.0f / 3 * (sq.x + sq.y));
    }

    void BoxGeometry::computeAabb(Aabb* aabb, const Transform& trans) const {
        Vector3D transX = (halfXAxis * trans.rotation).abs();
        Vector3D transY = (halfYAxis * trans.rotation).abs();
        Vector3D transZ = (halfZAxis * trans.rotation).abs();

        Vector3D transW = transX + transY + transZ;
        aabb->setMin(trans.position - transW);
        aabb->setMax(trans.position + transW);
    }

    bool BoxGeometry::rayCast(const Vector3D& begin, const Vector3D& end, RaycastHit* hit) const {
        float beginX = begin.x,      beginY = begin.y,      beginZ = begin.z;
        float endX   = end.x,        endY   = end.y,        endZ   = end.z;
        float halfX  = halfExtents.x, halfY = halfExtents.y, halfZ = halfExtents.z;
        float offsetX = endX - beginX, offsetY = endY - beginY, offsetZ = endZ - beginZ;

        float minX = 0.0f, minY = 0.0f, minZ = 0.0f;
        float maxX = 1.0f, maxY = 1.0f, maxZ = 1.0f;

        if (std::abs(offsetX) < FLOAT_TOL)
            if (beginX > -halfX && beginX < halfX) return false;
        else {
            float invOffsetX = 1.0f / offsetX;
            float t1 = -invOffsetX * (halfX + beginX);
            float t2 = invOffsetX * (halfX - beginX);
            if (t1 > t2) {
                float tmp = t1;
                t1 = t2;
                t2 = tmp;
            }
            if (t1 > 0.0f) minX = t1;
            if (t2 < 1.0f) maxX = t2;
        }

        if (std::abs(offsetY) < FLOAT_TOL)
            if (beginY > -halfY && beginY < halfY) return false;
        else {
            float invOffsetY = 1.0f / offsetY;
            float t1 = -invOffsetY * (halfY + beginY);
            float t2 = invOffsetY * (halfY - beginY);
            if (t1 > t2) {
                float tmp = t1;
                t1 = t2;
                t2 = tmp;
            }
            if (t1 > 0.0f) minY = t1;
            if (t2 < 1.0f) maxY = t2;
        }

        if (std::abs(offsetZ) < FLOAT_TOL)
            if (beginZ > -halfZ && beginZ < halfZ) return false;
        else {
            float invOffsetZ = 1.0f / offsetZ;
            float t1 = -invOffsetZ * (halfZ + beginZ);
            float t2 = invOffsetZ * (halfZ - beginZ);
            if (t1 > t2) {
                float tmp = t1;
                t1 = t2;
                t2 = tmp;
            }
            if (t1 > 0.0f) minZ = t1;
            if (t2 < 1.0f) maxZ = t2;
        }

        if (minX >= 1.0f || minY >= 1.0f || minZ >= 1.0f || maxX <=0.0f || maxY <= 0.0f || maxZ <= 0.0f) return false;

        float min = minX, max = maxX;
        int hitDirection = 0;

        if (minY > min) {
            min = minY;
            hitDirection = 1;
        }
        if (minZ > min) {
            min = minZ;
            hitDirection = 2;
        }
        if (maxY < max) max = maxY;
        if (maxZ < max) max = maxZ;

        if (min > max || std::abs(min) <= FLOAT_TOL) return false;

        switch (hitDirection) {
            case 0: hit->normal.set(offsetX > 0.0f ? -1.0f : 1.0f, 0.0f, 0.0f); break;
            case 1: hit->normal.set(0.0f, offsetY > 0.0f ? -1.0f : 1.0f, 0.0f); break;
            case 2: hit->normal.set(0.0f, 0.0f, offsetZ > 0.0f ? -1.0f : 1.0f);
        }

        hit->position.set(beginX + min * offsetX, beginY + min * offsetY, beginZ + min * offsetZ);
        hit->fraction = min;
        return true;
    }

    void BoxGeometry::computeLocalSupportingVertex(const Vector3D& in, Vector3D* out) const {
        Vector3D gjkMargins(gjkMargin, gjkMargin, gjkMargin);
        gjkMargins = tMin(gjkMargins, halfExtents);

        Vector3D coreExtents = (halfExtents - gjkMargins).abs();
        out->set(coreExtents.x, coreExtents.y, coreExtents.z);
    }
}