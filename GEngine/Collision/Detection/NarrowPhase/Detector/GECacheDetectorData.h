#ifndef GECACHEDETECTORDATA_H
#define GECACHEDETECTORDATA_H

#include "../GjkEpa/GEGjkCache.h"

namespace ge {
    struct CacheDetectorData {
        GjkCache* gjkCache;

        CacheDetectorData() {
            gjkCache = new GjkCache();
        }

        ~CacheDetectorData() {
            delete gjkCache;
        }
        
        void clear() {
            if (gjkCache != nullptr) gjkCache->clear();
        }
    };
}
#endif