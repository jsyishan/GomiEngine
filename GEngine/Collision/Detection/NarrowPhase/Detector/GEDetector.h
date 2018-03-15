#ifndef GEDETECTOR_H
#define GEDETECTOR_H

#include <vector>

#include "../../../../Math/GEVector.h"
#include "../../../../Math/GETransform.h"
#include "../../../../Basis/GESettings.h"
#include "../../../Geometry/GEGeometry.h"
#include "GECacheDetectorData.h"

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

        DetectorResultPoint() {
            depth = 0.0f;
            id = 0;
        }
    };

    struct DetectorResult {
        
        std::vector<DetectorResultPoint> points;
        int numPoints;

        Vector3D normal;
        bool incremental;

        DetectorResult() {
            incremental = false;

            for (int i = 0; i < max_manifold_points_number; ++i) {
                DetectorResultPoint point;
                points.push_back(point);
            }
        }

        float getMaxDepth() const {
            float max = 0.0f;
            for (int i = 0; i < numPoints; ++i) {
                if (points[i].depth > max) {
                    max = points[i].depth;
                }
            }
            return max;
        }

        void clear() {
            numPoints = 0;
            normal.zero();
            for (auto p : points) {
                p.depth = 0.0f;
                p.id = 0;
                p.position1.zero();
                p.position2.zero();
            }
        }
    };

    class Detector {
    public:
        //compute the contact manifold of the two Geometry
        void detect(DetectorResult* result, Geometry* geo1, Geometry* geo2, const Transform& trans1, const Transform& trans2, CacheDetectorData* data);

    protected:
        bool isSwapped;

        Detector(bool swapped);

        void setNormal(DetectorResult* result, const Vector3D& n) const;
        void addPoint(DetectorResult* result, const Vector3D& p1, const Vector3D& p2, float depth, int id) const;
        virtual void detectImpl(DetectorResult* result, Geometry* geo1, Geometry* geo2, const Transform& trans1, const Transform& trans2, CacheDetectorData* data);
    };

    Detector::Detector(bool swapped) {
        isSwapped = swapped;
    }

    inline void Detector::detect(DetectorResult* result, Geometry* geo1, Geometry* geo2, const Transform& trans1, const Transform& trans2, CacheDetectorData* data) {
        result->clear();
        if (isSwapped) {
            detectImpl(result, geo2, geo1, trans1, trans2, data);
        } else {
            detectImpl(result, geo1, geo2, trans1, trans2, data);
        }
    }

    inline void Detector::setNormal(DetectorResult* result, const Vector3D& n) const {
        result->normal = n;
        if (isSwapped) result->normal.reverse();
    }

    inline void Detector::addPoint(DetectorResult* result, const Vector3D& p1, const Vector3D& p2, float depth, int id) const {
        DetectorResultPoint point = result->points[result->numPoints++];
        point.depth = depth;
        point.id = id;
        if (isSwapped) {
            point.position1 = p2;
            point.position2 = p1;
        } else {
            point.position1 = p1;
            point.position2 = p2;
        }
    }
}
#endif