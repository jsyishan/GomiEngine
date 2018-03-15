#include "GEHelper.h"
#include "GEVector.h"
#include "GEMatrix33.h"
#include "GEQuaternion.h"

namespace ge {

    // Constants
    // Vector
    Vector2D Vector2D::vec2_zero = Vector2D(0.0f, 0.0f);
    Vector3D Vector3D::vec3_zero = Vector3D(0.0f, 0.0f, 0.0f);

    // Mat3
    Matrix33 Matrix33::m33_zero = Matrix33(
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f);

    Matrix33 Matrix33::m33_id = Matrix33(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f);

    // Quat
    Quaternion Quaternion::quat_zero = Quaternion(0.0f, Vector3D::vec3_zero);

    // GJK/EPA
    int projectingOrigin(const Vector3D& v1, const Vector3D& v2, Vector3D* out) {
        Vector3D v12 = v2 - v1; // v2 -> v1

        float d = v12 * v12;
        float t = v12 * v1;
        t = -t / d;

        if (t < 0.0f) {
            out->set(v1.x, v1.y, v1.z);
            return 1;
        }
        if (t > 1.0f) {
            out->set(v2.x, v2.y, v2.z);
            return 2;
        }

        out->set(Vector3D(t * v12 + v1));
        return 3;
    }

    int projectingOrigin(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3, Vector3D* out) {
        Vector3D v12 = v2 - v1; // v1 -> v2
        Vector3D v23 = v3 - v2; // v2 -> v3
        Vector3D v31 = v1 - v3; // v3 -> v1

        Vector3D n = v12 ^ v23;
        Vector3D n12 = v12 ^ n;
        Vector3D n23 = v23 ^ n;
        Vector3D n31 = v31 ^ n;

        float d12 = v1 * n12;
        float d23 = v2 * n23;
        float d31 = v3 * n31;

        float minD = -1.0f;
        Vector3D minV;
        int minI = 0;   // index of voronoi region

        //voronoi
        if (d12 < 0.0f) {
            int b =  projectingOrigin(v1, v2, out);
            float d = out->magnitudeWithoutSqrt();
            minI = b;
            minD = d;
            minV = *out;
        }

        if (d23 < 0.0f) {
            int b = projectingOrigin(v2, v3, out);
            float d = out->magnitudeWithoutSqrt();            
            if (minD < 0.0f || d < minD) {
                minI = b << 1;
                minD = d;
                minV = *out;
            }
        }

        if (d31 < 0.0f) {
            int b = projectingOrigin(v1, v3, out);
            float d = out->magnitudeWithoutSqrt();
            if (minD < 0 || d < minD) {
				minI = b & 1 | (b & 2) << 1;
				minD = d;
                minV = *out;
			}
        }

        if (minD > 0.0f) {
            out->set(minV);
            return minI;
        }


        float dn = v1 * n.normalize();
        float l2 = n * n;
        l2 = dn / l2;
        out->set(n * dn / (n * n)); //projection
        return 7;
    }

    // int projectingOrigin(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3, const Vector3D& v4, Vector3D* out) {

    // }
}
