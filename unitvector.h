#ifndef UNITVECTOR_H
#define UNITVECTOR_H
#include "point3d.h"

class UnitVector
{
public:
    UnitVector();
    point3D normalize(point3D v1);

};

#endif // UNITVECTOR_H
