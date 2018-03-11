#include "GEHelper.h"
#include "GEVector.h"
#include "GEMatrix33.h"
#include "GEQuaternion.h"

namespace ge {

    // Constants
    // Vector
    Vector2D Vector2D::vec2_zero = Vector2D(0.0f, 0.0f);
    Vector3D Vector3D::vec3_zero = Vector3D(0.0f, 0.0f, 0.0f);

    //Mat3
    Matrix33 Matrix33::m33_zero = Matrix33(
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f);

    Matrix33 Matrix33::m33_id = Matrix33(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f);

    //Quat
    Quaternion Quaternion::quat_zero = Quaternion(0.0f, Vector3D::vec3_zero);
}
