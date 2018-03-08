#ifndef GEOBJECT_H
#define GEOBJECT_H

#include <cstring>
#include <iostream>

#include "../Math/GEVector.h"
#include "../Math/GEQuaternion.h"

namespace ge {

    class Object {
    public:
        Object();
        Object(std::string n):name(n) {}
        virtual ~Object();

        bool operator!() const;
        bool operator==(const Object& obj);
        bool operator!=(const Object& obj);

        //Destroy an existing object
        static void destroy(Object* obj);

        //Make a copy of an existing object
        static Object* instantiate(const Object& obj);

        //...
        //Instantiate on the specific position
        static Object* instantiate(const Object& obj, const Vector3D& pos);

        //...
        //Instantiate on the specific position with the specific rotation
        static Object* instantiate(const Object& obj, const Vector3D& pos, const Quaternion& rot);
        
    protected:
        std::string name;
        std::string tag;
        void* gameObject;
    };

    inline Object::Object() {
        name = "object";
        tag = "default";
        gameObject = nullptr;
    }

    inline bool Object::operator!() const {
        if (gameObject) return true;
        return false;
    }

    inline bool Object::operator==(const Object& obj) {
        if (gameObject == obj.gameObject) return true;
        return false;
    }

    inline bool Object::operator!=(const Object& obj) {
        if (gameObject != obj.gameObject) return true;
        return false;
    }
}

#endif