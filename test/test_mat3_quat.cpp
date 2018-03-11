#include <iostream>

#include "../GEngine/Math/GEMatrix33.h"
#include "../GEngine/Math/GEQuaternion.h"

int main() {
    ge::Matrix33 m(
        1.0f, 0.4f, 0.0f,
        0.0f, 0.8f, 0.4f,
        0.0f, 0.0f, 0.2f
    );

   // std::cout << m.e11 << " " << m.e12 << " " << m.e13 << std::endl;

    ge::Quaternion q(m);

    std::cout << q.v.x << "\t" << q.v.y << "\t" << q.v.z << "\t" << q.n << std::endl;

    return 0;
}