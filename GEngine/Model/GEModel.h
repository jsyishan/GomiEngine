#ifndef GEMODEL_H
#define GEMODEL_H

#include "../Math/GEVector.h"
#include "../Basis/GESOA.h"

namespace ge {
    class Model {
    public:
        enum type {
            model_type_edge = 0,
            model_type_circle = 1,
            model_type_polygon = 2
        };

        Model();
        virtual ~Model() {}

        type getType() const;
        virtual Model* duplicate(SmallObjectAllocator* allocator) const = 0;
        
    };
}


#endif