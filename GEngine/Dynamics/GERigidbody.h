#ifndef GERIGIDBODY_H
#define GERIGIDBODY_H

#include "../Math/GEMatrix33.h"
#include "../Math/GEVector.h"
#include "../Math/GEQuaternion.h"
#include "../Basis/GEObject.h"

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

    private:
        Vector3D angularDrag;
        Vector3D angularVelocity;

        Vector3D linearVelocity;
        Vector3D linearVelocityBody;
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

        rigidbodyType type;
        bool isActive;
    };
}


#endif