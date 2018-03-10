#ifndef GEAABB_H
#define GEAABB_H

#include "../../Math/GEVector.h"
#include "../../Math/GEHelper.h"

namespace ge {

    // The axis-aligned bounding box
    class Aabb {
    public:
        Aabb();
        Aabb(const Vector3D& min, const Vector3D& max);

        const Vector3D& getMin() const;
        const Vector3D& getMax() const;
        Vector3D getCenter() const;
        Vector3D getExtents() const;
        Aabb getIntersection(const Aabb& other) const;

        void setMin(const Vector3D& min);
        void setMax(const Vector3D& max);

        void combine(const Aabb& other);
        bool overlap(const Aabb& other);
    private:
        //minimum and maximum point of AABB
        Vector3D min_point;
        Vector3D max_point;
    };

    inline Aabb::Aabb() {
        min_point = Vector3D::vec3_zero;
        max_point = Vector3D::vec3_zero;
    }

    inline Aabb::Aabb(const Vector3D& min, const Vector3D& max) {
        min_point = min;
        max_point = max;
    }

    inline const Vector3D& Aabb::getMin() const {
        return min_point;
    }

    inline const Vector3D& Aabb::getMax() const {
        return max_point;
    }

    inline Vector3D Aabb::getCenter() const {
        return (max_point + min_point) * 0.5f;
    }

    inline Vector3D Aabb::getExtents() const {
        return (max_point - min_point) * 0.5f;
    }

    inline Aabb Aabb::getIntersection(const Aabb& other) const{
        return Aabb(max(other.max_point, max_point), min(other.min_point, min_point));
    }

    inline void Aabb::setMin(const Vector3D& min) {
        min_point = min;
    }

    inline void Aabb::setMax(const Vector3D& max) {
        max_point = max;
    }

    inline void Aabb::combine(const Aabb& other) {
        min_point = min(min_point, other.min_point);
        max_point = max(max_point, other.max_point);
    }

    //returns whether *this and other intersect
    inline bool Aabb::overlap(const Aabb& other) {
        return (
          min_point.x < other.max_point.x && max_point.x > other.min_point.x &&
          min_point.y < other.max_point.y && max_point.y > other.min_point.y &&
          min_point.z < other.max_point.z && max_point.z > other.min_point.z
        );
    }
}

#endif // !GEAABB_H
