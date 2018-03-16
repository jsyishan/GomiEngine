#ifndef GEEPAPOLYHEDRON_H
#define GEEPAPOLYHEDRON_H

#include "GEEpaVertex.h"
#include "GEEpaTriangle.h"
#include "../../../../Math/GEVector.h"
#include "../../../../Basis/GESettings.h"

namespace ge {

    class EpaPolyhedron {
    public:
        //State of Epa Polyhedron
        enum PolyhedronState {
            polyhedron_state_ok,
            polyhedron_state_invalid_triangle,
            polyhedron_state_no_adjacent_pair_index,
            polyhedron_state_no_adjacent_triangle,
            polyhedron_state_edge_loop_broken,
            polyhedron_state_no_outer_triangle,
            polyhedron_state_triangle_invisible
        };

        EpaPolyhedron();
        ~EpaPolyhedron();

    private:
        EpaVertex* vertices;
        int numVerts;   // the number of vertices

        EpaTriangle* triList;   // triangle list
        EpaTriangle* triListLast;
        int numTris;   // the number of triangles

        EpaTriangle* triPool;
        EpaVertex* vertPool;

        Vector3D center;
        PolyhedronState status;
    };

    EpaPolyhedron::EpaPolyhedron() {
        vertices = new EpaVertex[max_epa_vertices];
        numVerts = 0;

        triList = nullptr;
        triListLast = nullptr;
        numTris = 0;

        triPool = nullptr;
        vertPool = nullptr;
    }
}

#endif