#ifndef GEDETECTOR_H
#define GEDETECTOR_H

#include <vector>

#include "../../../../Math/GEVector.h"
#include "../../../../Math/GETransform.h"
#include "../../../../Basis/GESettings.h"
#include "../../../Geometry/GEGeometry.h"

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

    private:
        bool isSwapped;

        Detector(bool swapped);

        void setNormal(DetectorResult* result, const Vector3D& n) const;
        void addPoint(DetectorResult* result, const Vector3D& p1, const Vector3D& p2, float depth, float id) const;
        virtual void detectImpl(DetectorResult* result, Geometry* geo1, Geometry* geo2, const Transform& trans1, const Transform& trans2)
    };

    Detector::Detector(bool swapped) {
        isSwapped = swapped;
    }
}
#endif