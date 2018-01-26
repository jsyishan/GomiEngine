#include <iostream>
#include "../include/math/GEVector.h"

int main() {
    ge::Vector v(1.0, 2.0, 3.0);
    ge::Vector u(2.0, 5.0, -1.5);
    
    std::cout << "v = {" << v.x << ", " << v.y << ", " << v.z << "}" << std::endl;
    std::cout << "u = {" << u.x << ", " << u.y << ", " << u.z << "}" << std::endl;

    std::cout << "u * v = " << v * u << std::endl;

    ge::Vector w = u ^ v;
    std::cout << "u x v = " << "{" << w.x << ", " << w.y << ", " << w.z << "}" << std::endl;

    ge::Vector a = u + v;
    std::cout << "u + v = " << "{" << a.x << ", " << a.y << ", " << a.z << "}" << std::endl;

    std::cout << "[u v w] = " << ge::scalarTripleProduct(u, v, w) << std::endl;

    std::cout << "normalize(u) = {" << (~u).x << ", " << (~u).y << ", " << (~u).z << "}" << std::endl;

    return 0;
}
