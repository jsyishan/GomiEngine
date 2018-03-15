#ifndef GEGJKCACHE_H
#define GEGJKCACHE_H

#include "../../../../Math/GEVector.h"

namespace ge {
    struct GjkCache {
        Vector3D preClosestDir;
        
        void clear() {
            preClosestDir.zero();
        }
    };
}

#endif