#include <cmath>

#include "GEQuaternion.h"
#include "GEVector.h"
#include "GEMatrix33.h"
#include "GEHelper.h"
#include "GEConstant.h"

namespace ge {

    float getAngle(const Quaternion& q) {
        return 2 * std::acos(q.n);
    }

    Vector3D getAxis(const Quaternion& q) {
        Quaternion p = q;
        return p.getVector().normalize();
    }

    Quaternion rotate(const Quaternion& q1, const Quaternion& q2) {
        return q1 * q2 * (~q1);
    }

    Vector3D rotate(const Quaternion& q, const Vector3D& v) {
        Quaternion p = q * v * (~q);
        return p.getVector();
    }

    Vector3D rotate(const Vector3D& v, const Quaternion& q) {
        Quaternion p = q * v * (~q);
        return p.getVector();
    }

    Quaternion constructFromEulerAngles(float x, float y, float z) {
        Quaternion q;
        float half_roll = degreesToRadians(x) / 2;
        float half_pitch = degreesToRadians(y) / 2;
        float half_yaw = degreesToRadians(z) / 2;

        float cos_yaw_cos_pitch, sin_yaw_sin_pitch, cos_yaw_sin_pitch, sin_yaw_cos_pitch;
        cos_yaw_cos_pitch = std::cos(half_yaw) * std::cos(half_pitch);
        sin_yaw_sin_pitch = std::sin(half_yaw) * std::sin(half_pitch);
        cos_yaw_sin_pitch = std::cos(half_yaw) * std::sin(half_pitch);
        sin_yaw_cos_pitch = std::sin(half_yaw) * std::cos(half_pitch);

        q.n = cos_yaw_cos_pitch * std::cos(half_roll) + sin_yaw_sin_pitch * std::sin(half_roll);
        q.v.x = cos_yaw_cos_pitch * std::sin(half_roll) - sin_yaw_sin_pitch * std::cos(half_roll);
        q.v.y = cos_yaw_sin_pitch * std::cos(half_roll) + sin_yaw_cos_pitch * std::sin(half_roll);
        q.v.z = sin_yaw_cos_pitch * std::cos(half_roll) - cos_yaw_sin_pitch * std::sin(half_roll);

        return q;
    }

    Quaternion constructFromEulerAngles(const Vector3D& v) {
        return constructFromEulerAngles(v.x, v.y, v.z);
    }

    Vector3D getEulerAngles(const Quaternion& q) {
        Vector3D v;
        float r11, r12, r13, r21, r31, r32, r33;
        float tmp;

        r11 = q.n * q.n + q.v.x * q.v.x - q.v.y * q.v.y - q.v.z * q.v.z;
        r21 = 2 * (q.v.x * q.v.y + q.n * q.v.z);
        r31 = 2 * (q.v.x * q.v.z - q.n * q.v.y);
        r32 = 2 * (q.v.y * q.v.z + q.n * q.v.x);
        r33 = q.n * q.n - q.v.x * q.v.x - q.v.y * q.v.y + q.v.z * q.v.z;

        tmp = std::fabs(r31);
        if (tmp > 0.99999f) {
            r12 = 2 * (q.v.x * q.v.y - q.n * q.v.z);
            r13 = 2 * (q.v.x * q.v.z + q.n * q.v.y);

            v.x = 0.0f;                                             //  roll
            v.y = radiansToDegrees(-(PI/2) * r31 / tmp);            //  pitch
            v.z = radiansToDegrees(std::atan2(-r12, -r31 * r13));   //  yaw

            return v;
        }

        v.x = radiansToDegrees(std::atan2(r32, r33));   //  roll
        v.y = radiansToDegrees(std::asin(-r31));        //  pitch
        v.z = radiansToDegrees(std::atan2(r21, r11));   //  yaw

        return v;
    }
}