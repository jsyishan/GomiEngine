#ifndef GESPHERESPHEREDETECTOR_H
#define GESPHERESPHEREDETECTOR_H

#include "GEDetector.h"

namespace ge {
    class SphereSphereDetector : public Detector {
    public:
        SphereSphereDetector();
    private:
        void detectImpl(DetectorResult*, Geometry*, Geometry*, const Transform&, const Transform&, CacheDetectorData*) override;
    };

    inline SphereSphereDetector::SphereSphereDetector() : Detector(false) {}
}

#endif