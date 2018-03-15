#ifndef GEEPAVERTEX_H
#define GEEPAVERTEX_H

#include <random>
#include "../../../../Math/GEVector.h"

class EpaTriangle;

namespace ge {
    class EpaVertex {
    public:
        Vector3D vertex;
        Vector3D w1, w2;

        int id;

        EpaVertex();
        ~EpaVertex();

        void init(const Vector3D& v, const Vector3D& _w1, const Vector3D& _w2);
        //remove all refs
        void remove();

    private:
        EpaVertex* next;
        EpaVertex* tmpNext;
        EpaTriangle* tmpOuter;
    };

    inline EpaVertex::EpaVertex() {
        //c++ random
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 1000);
        id = dis(gen);
    }

    inline EpaVertex::~EpaVertex() {
        if (next != nullptr) delete next;
        if (tmpNext != nullptr) delete tmpNext;
        if (tmpOuter != nullptr) delete tmpOuter;
    }

    inline void EpaVertex::init(const Vector3D& v, const Vector3D& _w1, const Vector3D& _w2) {
        vertex = v;
        w1 = _w1;
        w2 = _w2;
        next = nullptr;
        tmpNext = nullptr;
        tmpOuter = nullptr;
    }

    inline void EpaVertex::remove() {
        next = nullptr;
        tmpNext = nullptr;
        tmpOuter = nullptr;
    }
}

#endif