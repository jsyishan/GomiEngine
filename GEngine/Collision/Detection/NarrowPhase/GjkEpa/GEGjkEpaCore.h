#ifndef GEGJKCORE_H
#define GEGJKCORE_H

namespace ge {
    struct GjkEpaResultState {
        enum ResultState {
            SUCCEEDED = 0x00,
            GJK_NOT_CONVERGE = 0x01,
            GJK_FAILED_TO_MAKE_TETRAHEDRON = 0x02,
            EPA_NOT_CONVERGE = 0x11,
            EPA_FAILED_TO_INIT = 0x12,
            EPA_FAILED_TO_ADD_VERTEX = 0x13
        };

        ResultState resultState;
    };
}

#endif