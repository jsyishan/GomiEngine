#ifndef GEMODEL_H
#define GEMODEL_H

#include "../Math/GEVector.h"
#include "../Basis/GESOA.h"
#include "../Basis/GEObject.h"

namespace ge {
    class Model : public Object{
    public:

        Model();
        virtual ~Model() = 0;

        virtual Model* duplicate(SmallObjectAllocator* allocator) const = 0;

    };
}


#endif