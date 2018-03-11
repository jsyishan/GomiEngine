#include <cmath>

#include "GEMatrix33.h"
#include "GEQuaternion.h"

namespace ge {

    Matrix33::Matrix33(const Quaternion& q) {
        float x = q.v.x,
              y = q.v.y,
              z = q.v.z;

        float x2 = x * x,
              y2 = y * y,
              z2 = z * z;

        float xx = x * x2,
              yy = y * y2,
              zz = z * z2;

        float xy = x * y2,
              yz = y * z2,
              xz = x * z2;
         
        float nx = q.n * x2,
              ny = q.n * y2,
              nz = q.n * z2;

        e11 = 1 - yy - zz; e12 = xy - nz;     e13 = xz + ny;
        e21 = xy + nz;     e22 = 1 - xx - zz; e23 = yz - nx;
        e31 = xz - ny;     e32 = yz + nx;     e33 = 1 - xx - yy;
    }

    Matrix33::Matrix33(const Vector3D& euler) {
        float sx = std::sin(euler.x),
              sy = std::sin(euler.y),
              sz = std::sin(euler.z);

        float cx = std::cos(euler.x),
              cy = std::cos(euler.y),
              cz = std::cos(euler.z);
        
        e11 = cy * cz;                e12 = -cy * sz;               e13 = sy;
        e21 = cx * sz + cz * sx * sy; e22 = cx * cz - sx * sy * sz; e23 = -cy * sx;
        e31 = sx * sz - cx * cz * sy; e32 = cz * sx + cx * sy * sz; e33 = cx * cy;
    }
}