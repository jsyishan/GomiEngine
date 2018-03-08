#ifndef GETRANSFORM_H
#define GETRANSFORM_H

#include "GEVector.h"
#include "GEQuaternion.h"

namespace ge {

    class Transform {
    public:
        Vector3D position;
        Vector3D rotation;
        Vector3D scale;

        Transform();
        Transform(const Transform& trans);
        Transform(const Vector3D& pos);
        Transform(const Vector3D& pos, const Vector3D& rot);
        Transform(const Vector3D& pos, const Quaternion& rot);

        //rotate around as for an Euler Angle
        //rotation of rot.x degrees around the x axis, etc.
        void rotate(const Vector3D& rot);

        //rotate around as for a Quaternion
        void rotate(const Quaternion& rot);

        // //rotate about axis passing through the point
        // void rotateAround(const Vector3D& point, const Vector3D& axis, float angle);

        //move to the position
        void translate(const Vector3D& pos);

    };

    inline Transform::Transform() {
        position = rotation = Vector3D::vec3_zero;
        scale = Vector3D(1.0f, 1.0f, 1.0f);
    }

    inline Transform::Transform(const Transform& trans) {
        position = trans.position;
        rotation = trans.rotation;
        scale = trans.scale;
    }

    inline Transform::Transform(const Vector3D& pos) {
        position = pos;
        rotation = Vector3D::vec3_zero;
        scale = Vector3D(1.0f, 1.0f, 1.0f);
    }

    inline Transform::Transform(const Vector3D& pos, const Vector3D& rot) {
        position = pos;
        rotation = rot;
        scale = Vector3D(1.0f, 1.0f, 1.0f);
    }

    inline Transform::Transform(const Vector3D& pos, const Quaternion& rot) {
        position = pos;
        rotation = getEulerAngles(rot);
        scale = Vector3D(1.0f, 1.0f, 1.0f);
    }

    inline void Transform::rotate(const Vector3D& rot) {
        rotation.x = rot.x;
        rotation.y = rot.y;
        rotation.z = rot.z;
    }

    inline void Transform::rotate(const Quaternion& rot) {
        Vector3D tmpRotation = getEulerAngles(rot);
        rotation.x = tmpRotation.x;
        rotation.y = tmpRotation.y;
        rotation.z = tmpRotation.z;
    }

    // inline void Transform::rotateAround(const Vector3D& point, const Vector3D& axis, float angle) { }

    inline void Transform::translate(const Vector3D& pos) {
        position.x = pos.x;
        position.y = pos.y;
        position.z = pos.z;
    }
}

#endif