#include "GEObject.h"

namespace ge {

    Object::~Object() {
        gameObject = nullptr;
    }

    void Object::destroy(Object* obj) {

    }

    Object* Object::instantiate(const Object& obj) {

    }

    Object* Object::instantiate(const Object& obj, const Vector3D& pos) {

    }

    Object* Object::instantiate(const Object& obj, const Vector3D& pos, const Quaternion& rot) {

    }
}