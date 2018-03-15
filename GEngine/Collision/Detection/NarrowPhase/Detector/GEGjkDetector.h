#ifndef GEGJKDETECTOR_H
#define GEGJKDETECTOR_H

#include "GEDetector.h"

namespace ge {
    class GjkDetector : public Detector {
    public:
        GjkDetector();
    private:
        void detectImpl(DetectorResult* ,Geometry*, Geometry*, const Transform&, const Transform&, CacheDetectorData*) override;
    };

    inline GjkDetector::GjkDetector() : Detector(false) {}
}


#endif