#ifndef GEDETECTOR_H
#define GEDETECTOR_H

#include "../../../../Math/GEVector.h"

namespace ge {

    struct DetectorResultPoint {

        //first closest collisionpoint
        Vector3D position1;

        //second closes collisiont point
        Vector3D position2;

        //amount of overlap
        //negative if two geometries separated
        float depth;

        //id of the result point
        int id;
    };

    struct DetectorResult {
        
    };

    class Detector {
    public:

    private:
        bool isSwapped;

        Detector(bool swapped);

        void setNormal();
    };
}
#endif