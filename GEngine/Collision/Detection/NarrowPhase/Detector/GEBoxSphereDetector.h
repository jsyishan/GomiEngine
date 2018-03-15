#ifndef GEBOXSPHEREDETECTOR_H
#define GEBOXSPHEREDETECTOR_H

#include "GEDetector.h"

namespace ge {
    class BoxSphereDetector : public Detector {
    public:
        BoxSphereDetector();
    private:
        void detectImpl(DetectorResult*, Geometry*, Geometry*, const Transform&, const Transform&, CacheDetectorData*) override;
    };

    inline BoxSphereDetector::BoxSphereDetector() : Detector(false) {}
}

#endif