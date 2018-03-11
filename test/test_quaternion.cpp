#include <iostream>

#include "../GEngine/Math/GEQuaternion.h"

int main() {
    ge::Quaternion q1 (1, 2, 3, 4);

    ge::Vector3D v1 = ge::getEulerAngles(q1);
    std::cout << v1.x << " " << v1.y << " " << v1.z << std::endl;

    return 0;
}