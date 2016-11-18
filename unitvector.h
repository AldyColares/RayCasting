#ifndef UNITVECTOR_H
#define UNITVECTOR_H
#include "point3d.h"
#include "math.h"

class UnitVector
{
public:
    UnitVector();
    Point3D normalize(Point3D v1);

};

#endif // UNITVECTOR_H
