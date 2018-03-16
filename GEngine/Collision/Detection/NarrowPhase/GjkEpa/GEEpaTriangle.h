#ifndef GEEPATRIANGLE_H
#define GEEPATRIANGLE_H

#include "GEEpaVertex.h"
#include "../../../../Math/GEVector.h"
#include "../../../../Basis/GESOA.h"

namespace ge {
    class EpaTriangle {
    public:
        static int count;
        int id;

        EpaTriangle();
        ~EpaTriangle();

        bool checkVisible(const Vector3D& from);
        bool init(EpaVertex* v1, EpaVertex* v2, EpaVertex* v3, const Vector3D& center, bool check);
        bool setAdjTriangle();
        bool removeAdjTriangle();

        //remove refs
        void remove();

    private:
        EpaTriangle* next;
        EpaTriangle* prev;

        EpaVertex* vertices;
        //adjacent
        EpaTriangle* adjTriangle;
        int adjIndex[3];
        int nextIndex[3];

        Vector3D normal;
        float dist;

        bool visibility;
    };

    inline EpaTriangle::EpaTriangle() {
        next = nullptr;
        prev = nullptr;

        vertices = new EpaVertex[3];
        adjTriangle = new EpaTriangle[3];
    
        nextIndex[0] = 1;
        nextIndex[1] = 2;
        nextIndex[2] = 0;

        dist = 0.0f;
        visibility = false;
    }

    inline EpaTriangle::~EpaTriangle() {
        if (next != nullptr) delete next;
        if (prev != nullptr) delete prev;

        delete[] vertices;
        delete[] adjTriangle;
    }

    inline bool EpaTriangle::checkVisible(const Vector3D& from) {
        return ((from - vertices[0].vertex) * normal > 0);
    }

    inline void EpaTriangle::remove() {
        next = nullptr;
        prev = nullptr;

        visibility = false;
        dist = 0.0f;

        for (int i = 0; i < 3; ++i) {
            vertices[i].remove();
            adjTriangle[i].remove();
        }
        adjIndex[0] = 0;
        adjIndex[1] = 0;
        adjIndex[2] = 0;
    }
}


#endif