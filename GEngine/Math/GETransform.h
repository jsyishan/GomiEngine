#ifndef GETRANSFORM_H
#define GETRANSFORM_H

#include "GEVector.h"
#include "GEMatrix33.h"
#include "GEQuaternion.h"

namespace ge {

    class Transform {
    public:
        Vector3D position;
        Matrix33 rotation;
        Vector3D scale;

        Transform();
        Transform(const Transform& trans);
        Transform(const Vector3D& pos);
        Transform(const Vector3D& pos, const Matrix33& m);
        Transform(const Vector3D& pos, const Quaternion& q);
        Transform(const Vector3D& pos, const Vector3D& euler);

        //rotate by the rotation matrix
        void rotate(const Matrix33& m);

        //rotate around as for an Euler Angle
        //rotation of rot.x degrees around the x axis, etc.
        void rotate(const Vector3D& euler);

        //rotate around as for a Quaternion
        void rotate(const Quaternion& q);

        // //rotate about axis passing through the point
        // void rotateAround(const Vector3D& point, const Vector3D& axis, float angle);

        //move to the position
        void translate(const Vector3D& pos);

        //Returns the rotation as a quaternion
        Quaternion getOrientation() const;
    };

    inline Transform::Transform() {
        position = Vector3D::vec3_zero;
        rotation = Matrix33::m33_id;
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

    inline Transform::Transform(const Vector3D& pos, const Matrix33& m) {
        position = pos;
        rotation = m;
        scale = Vector3D(1.0f, 1.0f, 1.0f);
    }

    inline Transform::Transform(const Vector3D& pos, const Vector3D& euler) {
        position = pos;
        rotation = Matrix33(euler);
        scale = Vector3D(1.0f, 1.0f, 1.0f);
    }

    inline Transform::Transform(const Vector3D& pos, const Quaternion& q) {
        position = pos;
        rotation = Matrix33(q);
        scale = Vector3D(1.0f, 1.0f, 1.0f);
    }

    inline void Transform::rotate(const Matrix33& m) {
        rotation = rotation * m;
    }

    inline void Transform::rotate(const Vector3D& euler) {
        rotation = rotation * Matrix33(euler);
    }

    inline void Transform::rotate(const Quaternion& q) {
        rotation = rotation * Matrix33(q);
    }

    // inline void Transform::rotateAround(const Vector3D& point, const Vector3D& axis, float angle) { }

    inline void Transform::translate(const Vector3D& pos) {
        position.x += pos.x;
        position.y += pos.y;
        position.z += pos.z;
    }

    inline Quaternion Transform::getOrientation() const {
        return Quaternion(rotation);
    }
}

#endif