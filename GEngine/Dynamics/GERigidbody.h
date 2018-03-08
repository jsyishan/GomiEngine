#ifndef GERIGIDBODY_H
#define GERIGIDBODY_H

#include "../Math/GEMatrix33.h"
#include "../Math/GEVector.h"
#include "../Math/GEQuaternion.h"
#include "../Basis/GEObject.h"
#include "../Math/GETransform.h"

namespace ge {

    //static rigidbody: mass == 0.0f, speed == 0.0f
    //kinematic rigidbody: mass == 0.0f, speed/velocity != 0.0f/NULL determined by user's assignment
    //dynamic rigidbody: mass > 0.0f, speed/velocity != 0.0f/NULL determined by forces
    enum rigidbodyType {
        rb_static = 0,
        rb_kinematic = 1,
        rb_dynamic = 2
    };

    class Rigidbody : public Object{
    public:
        Rigidbody();
        ~Rigidbody() override;

        //getter functions
        const Vector3D& getAngularDrag() const;
        const Vector3D& getAngularVelocity() const;

        const Vector3D& getLinearVelocity() const;
        const Vector3D& getLinearVelocityLocal() const;

        const Vector3D& getCenterOfMass() const;
        const Vector3D& getEuler() const;

        const Vector3D& getForces() const;
        const Vector3D& getMoments() const;

        float getMass() const;
        float getSpeed() const;

        const Matrix33& getInertia() const;
        const Quaternion& getOrientation() const;
        const Transform& getTransform() const;

        rigidbodyType getType() const;
        bool isAwake() const;

        //setter functions
        void setAngularDrag(const Vector3D& drag);
        void setAngularVelocity(const Vector3D& velocity);

        void setLinearVelocity(const Vector3D& velocity);

        void setForces(const Vector3D& f);
        void setSpeed(float s);

        void setInertia(const Matrix33& m);
        void setOrientation(const Quaternion& q);
        void setTransform(const Transform& trans);

        void setType(rigidbodyType t);
        void setAwake(bool flag);

    private:
        Vector3D angularDrag;
        Vector3D angularVelocity;

        //linear velocity in world coordinates
        Vector3D linearVelocity;

        //linear velocity in local coordinates
        Vector3D linearVelocityLocal;
        Vector3D linearVelocityDrag;

        Vector3D centerOfMass;
        Vector3D eulerAngles;

        //total forces
        Vector3D forces;

        //total moments
        Vector3D moments;

        float mass;
        float speed;

        Matrix33 inertia;
        Matrix33 inertiaInverse;
        Quaternion orientation;
        Transform transform;

        rigidbodyType type;
        bool isActive;
    };

    Rigidbody::Rigidbody() {
        //all Vector attributes should be set to a zero Vector
        angularDrag = angularVelocity = Vector3D::vec3_zero;
        linearVelocity = linearVelocityLocal = linearVelocityDrag = Vector3D::vec3_zero;
        centerOfMass = eulerAngles = forces = moments = Vector3D::vec3_zero;

        //other else
        //...
        mass = speed = 0.0f;
        inertia = inertiaInverse = Matrix33::m33_zero;
        transform = Transform();
    }
}


#endif