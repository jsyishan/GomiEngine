#include <iostream>

#include "../GEngine/Math/GETransform.h"

int main() {
    ge::Transform t1(ge::Vector3D(1.0f, 2.0f, 3.0f));
    ge::Transform t2, t3;
    t3 = t2 = t1;

    std::cout << t1.position.x << "   " << t3.position.y << "\t" << t3.scale.x << std::endl;
    return 0;
}
