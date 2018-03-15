#ifndef GEEPATRIANGLE_H
#define GEEPATRIANGLE_H

#include <vector>
#include "../../../../Math/GEVector.h"

class EpaVertex;

namespace ge {
    class EpaTriangle {
    public:
        static int count;
        int id;
    private:
        EpaTriangle* next;
        EpaTriangle* prev;

        std::vector<EpaVertex> vertices;
        //adjacent
        std::vector<EpaTriangle> adjTriangle;
        std::vector<int> adjIndex;
        std::vector<int> nextIndex;

        Vector3D normal;
        float dist;
    };
}


#endif