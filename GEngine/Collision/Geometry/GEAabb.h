#ifndef GEAABB_H
#define GEAABB_H

#include "../../Math/GEVector.h"

namespace ge {
    class Aabb {
    public:
        Aabb();
        Aabb(const Vector3D& _min, const Vector3D& _max);

        const Vector3D& getMin() const;
        const Vector3D& getMax() const;
        Vector3D getCenter() const;
        Vector3D getExtents() const;
        Aabb getIntersection(const Aabb& other) const;

        void setMin(const Vector3D& _min);
        void setMax(const Vector3D& _max);

        void combine(const Aabb& other);
        bool overlap(const Aabb& other);
    private:
        //minimum and maximum point of AABB
        Vector3D min;
        Vector3D max;
    };

    inline Aabb::Aabb() {
        min = Vector3D::vec3_zero;
        max = Vector3D::vec3_zero;
    }

    inline Aabb::Aabb(const Vector3D& _min, const Vector3D& _max) {
        min = _min;
        max = _max;
    }

    inline const Vector3D& Aabb::getMin() const {
        return min;
    }

    inline const Vector3D& Aabb::getMax() const {
        return max;
    }

    inline Vector3D Aabb::getCenter() const {
        return (max + min) * 0.5f;
    }

    inline Vector3D Aabb::getExtents() const {
        return (max - min) * 0.5f;
    }

    inline Aabb Aabb::getIntersection(const Aabb& other) const{
        
    }
}

#endif // !GEAABB_H
