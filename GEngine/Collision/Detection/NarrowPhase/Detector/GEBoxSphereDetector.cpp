#include "GEBoxSphereDetector.h"

#include <cmath>

#include "../../../Geometry/GESphereGeometry.h"
#include "../../../Geometry/GEBoxGeometry.h"
#include "../../../../Math/GEVector.h"
#include "../../../../Math/GEHelper.h"
#include "../../../../Math/GEConstant.h"

namespace ge {
    void BoxSphereDetector::detectImpl(DetectorResult* result, Geometry* geo1, Geometry* geo2, const Transform& trans1, const Transform& trans2, CacheDetectorData* data) {
        SphereGeometry* sphere = dynamic_cast<SphereGeometry*>(geo1);
        BoxGeometry* box = dynamic_cast<BoxGeometry*>(geo2);

        result->incremental = false;

        Vector3D hExtents = box->getHalfExtents();
        float r = sphere->getRadius();

        //Box to Sphere
        Vector3D offset = trans1.position - trans2.position;
        Vector3D insideOffset = offset * trans2.rotation;

        //whether the sphere's center inside the box
        if (isAabbOverlap(-hExtents, hExtents, insideOffset, insideOffset)) {
            //min distance between the center of sphere and the box's surfaces which are vertical to both x/y/z axis
            Vector3D distance = hExtents - insideOffset.abs();

            Vector3D normalInsizeBox;
            float depth;
            //Projection Mask
            Vector3D projMask;
            float minDistance = tMin(distance.x, distance.y, distance.z);
            if (areFloatsSame(minDistance, distance.x)) {
                if (distance.x > 0) normalInsizeBox.set(1.0f, 0.0f, 0.0f);
                else normalInsizeBox.set(-1.0f, 0.0f, 0.0f);
                projMask.set(0.0f, 1.0f, 1.0f);
                depth = distance.x;
            } else if(areFloatsSame(minDistance, distance.y)) {
                if (distance.y > 0) normalInsizeBox.set(0.0f, 1.0f, 0.0f);
                else normalInsizeBox.set(0.0f, -1.0f, 0.0f);
                projMask.set(1.0f, 0.0f, 1.0f);
                depth = distance.y;
            } else {
                if (distance.z > 0) normalInsizeBox.set(0.0f, 0.0f, 1.0f);
                else normalInsizeBox.set(0.0f, 0.0f, -1.0f);
                projMask.set(1.0f, 1.0f, 0.0f);
                depth = distance.z;
            }

            //compute the closest point
            Vector3D base(projMask.x * insideOffset.x, projMask.y * insideOffset.y, projMask.z * insideOffset.z);
            Vector3D boxToClosestPointInsideBox(normalInsizeBox.x * hExtents.x, normalInsizeBox.y * hExtents.y, normalInsizeBox.z * hExtents.z);
            boxToClosestPointInsideBox += base;

            //World Space
            Vector3D boxToClosestPoint = boxToClosestPointInsideBox * trans2.rotation;
            Vector3D n = normalInsizeBox * trans2.rotation;
            setNormal(result, n);

            Vector3D pos1 = n * -r + trans1.position;
            Vector3D pos2 = trans2.position + boxToClosestPoint;
            addPoint(result, pos1, pos2, depth, 0);
            return;
        }

        //Outside
        Vector3D epsilonVec3(FLOAT_TOL, FLOAT_TOL, FLOAT_TOL);
        Vector3D negHExtents = -hExtents + epsilonVec3;
        hExtents -= epsilonVec3;
        Vector3D boxToClosestPointInsideBox = tClamp(insideOffset, negHExtents, hExtents);

        Vector3D closestPointToSphereInsideBox = insideOffset - boxToClosestPointInsideBox;

        float dist = closestPointToSphereInsideBox.magnitude();

        //no collision
        if (dist >= r) return;

        //World Space
        Vector3D boxToClosestPoint = boxToClosestPointInsideBox * trans2.rotation;
        Vector3D closestPointToSphere = closestPointToSphereInsideBox * trans2.rotation;
        Vector3D n = closestPointToSphere.normalize();
        setNormal(result, n);

        Vector3D pos1 = n * -r + trans1.position;
        Vector3D pos2 = trans2.position + boxToClosestPoint;
        addPoint(result, pos1, pos2, r - dist, 0);
    }
}