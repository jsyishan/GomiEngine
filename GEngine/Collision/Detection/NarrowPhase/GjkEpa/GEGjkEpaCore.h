#ifndef GEGJKCORE_H
#define GEGJKCORE_H

namespace ge {
    struct GjkEpaResultState {
        enum ResultState {
            gjk_succeeded = 0x00,
            gjk_not_converge = 0x01,
            gjk_failed_to_make_tetrahedron = 0x02,
            epa_not_converge = 0x11,
            epa_failed_to_init = 0x12,
            epa_failed_to_add_vertex = 0x13
        };

        ResultState resultState;
    };
}

#endif