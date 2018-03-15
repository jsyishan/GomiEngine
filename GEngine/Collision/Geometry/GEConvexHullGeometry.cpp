#include <new>

#include "GEConvexHullGeometry.h"
#include "../../Math/GEMatrix33.h"

namespace ge {

    Geometry* ConvexHullGeometry::clone(SmallObjectAllocator* allocator) const {
        void* mem = allocator->allocate(sizeof(ConvexHullGeometry));
        ConvexHullGeometry* clone = new (mem) ConvexHullGeometry(vertices);
        *clone = *this;
        return clone;
    }

    void ConvexHullGeometry::updateMass() {
        volume = 1.0f;
        inertiaCoeff = Matrix33().diagonal(1.0f, 1.0f, 1.0f);

        float minX = vertices[0].x, minY = vertices[0].y, minZ = vertices[0].z;
        float maxX = vertices[0].x, maxY = vertices[0].y, maxZ = vertices[0].z;

        for (int i = 1; i < size; ++i) {
            float tmpX = vertices[i].x, tmpY = vertices[i].y, tmpZ = vertices[i].z;
            if (tmpX < minX) minX = tmpX;
            else if (tmpX > maxX) maxX = tmpX;

            if (tmpY < minY) minY = tmpY;
            else if (tmpY > maxY) maxY = tmpY;

            if (tmpZ < minZ) minZ = tmpZ;
            else if (tmpZ > maxZ) maxZ = tmpZ;
        }

        float dx = maxX - minX, dy = maxY - minY, dz = maxZ - minZ;
        volume = dx * dy * dz;

        float diffCog = (
            (minX + maxX) * (minX + maxX) +
            (minY + maxY) * (minY + maxY) +
            (minZ + maxZ) * (minZ + maxZ)
        ) * 0.25f;

        dx = dx * dx * 0.25f;
        dy = dy * dy * 0.25f;
        dz = dz * dz * 0.25f;

        inertiaCoeff = Matrix33().diagonal(1.0f / 3 * (dy + dz) + diffCog, 1.0f / 3 * (dx + dz) + diffCog, 1.0f / 3 * (dx + dy) + diffCog);
    }

    void ConvexHullGeometry::computeAabb(Aabb* aabb, const Transform& trans) const {
        Vector3D margin(gjkMargin, gjkMargin, gjkMargin);

        Vector3D localVertice(vertices[0]);
        Vector3D worldVertice = localVertice * trans.rotation + trans.position;
        Vector3D min(worldVertice), max(worldVertice);

        for (int i = 1; i < size; ++i) {
            localVertice = vertices[i];
            worldVertice = localVertice * trans.rotation + trans.position;
            min.set(worldVertice.x, worldVertice.y, worldVertice.z);
            max.set(worldVertice.x, worldVertice.y, worldVertice.z);
        }

        aabb->setMin(min - margin);
        aabb->setMax(max + margin);
    }

    void ConvexHullGeometry::computeLocalSupportingVertex(const Vector3D& in, Vector3D* out) const {
        float maxDot = vertices[0] * in;
        int maxIndex = 0;

        for (int i = 1; i < size; ++i) {
            float dot = vertices[i] * in;
            if (dot > maxDot) {
                maxDot = dot;
                maxIndex = i;
            }
        }

        out->set(vertices[maxIndex].x, vertices[maxIndex].y, vertices[maxIndex].z);
    }
}