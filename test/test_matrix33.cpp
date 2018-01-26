#include <iostream>

#include "../GEngine/math/GEMatrix33.h"

void print(ge::Matrix33 m) {
    std::cout << 
        m.e11 << " " << m.e12 << " " << m.e13 << "\n" <<
        m.e21 << " " << m.e22 << " " << m.e23 << "\n" <<
        m.e31 << " " << m.e32 << " " << m.e33 << "\n" << std::endl;
}

int main() {
    ge::Matrix33 m1(
        1, 2, 3,
        2, 2, 1,
        1, 2, 0
    );
    ge::Matrix33 m2(
        1, 0, 1,
        2, 0, 2,
        3, 3, 4
    );

    std::cout << m1.det() << "\t" << m2.det() << std::endl;
    print(m1);
    print(m1.transpose());
    print(m1.inverse());
    print(m1 + m2);

    ge::Vector v(1, 2, 3);
    std::cout << (m1 * v).x << " " << (m1 * v).y << " " << (m1 * v).z << std::endl;

    return 0;
}