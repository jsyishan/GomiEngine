#ifndef GEGEOMETRY_H
#define GEGEOMETRY_H

#include "GEAabb.h"
#include "GERaycastHit.h"
#include "../../Math/GETransform.h"
#include "../../Basis/GESettings.h"

class Matrix33;

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
        virtual bool rayCast(const Vector3D& begin, const Vector3D& end, const Transform& trans, RaycastHit* hit) const;
        virtual void computeLocalSupportingVertex(const Vector3D& in, Vector3D* out) const = 0;

        Type getType() const;
        float getVolume() const;

        float getGjkMargin() const;
        void setGjkMargin(float margin);

    protected:
        Type type;
        float volume;
        bool isUseGjkRayCast;
        float gjkMargin;
        Matrix33 inertiaCoeff;  // I / m

        Geometry(Type type);
        virtual void updateMass() = 0;
        virtual void computeAabb(Aabb* aabb, const Transform& trans) const = 0;
        virtual bool rayCast(const Vector3D& begin, const Vector3D& end, RaycastHit* hit) const;
    };

    inline Geometry::Geometry(Type t) {
        type = t;
        volume = 0.0f;
        isUseGjkRayCast = false;
        gjkMargin = gjk_margin;
    }

    inline Geometry::Type Geometry::getType() const {
        return type;
    }

    inline float Geometry::getVolume() const {
        return volume;
    }

    inline float Geometry::getGjkMargin() const {
        return gjkMargin;
    }

    inline void Geometry::setGjkMargin(float margin) {
        if (margin < 0.0f) gjkMargin = 0.0f;
        else gjkMargin = margin;
    }

    inline bool Geometry::rayCast(const Vector3D& begin, const Vector3D& end, RaycastHit* hit) const {
        return false;
    }
}
#endif // !GEGEOMETRY_H
