#ifndef GEMODEL_H
#define GEMODEL_H

#include "../Math/GEVector.h"

namespace ge {
    class Model {
    public:
        float fMass;
        ge::Vector vPosition;
        ge::Vector vVelocity;
        ge::Vector vForces;

        Model();
        virtual void calcLoads() = 0;
        
    };
}


#endif