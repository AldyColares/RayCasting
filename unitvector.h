#ifndef UNITVECTOR_H
#define UNITVECTOR_H
#include "point3d.h"
#include "math.h"

class UnitVector
{
public:
    UnitVector();
    Point3D normalize(Point3D v1);
    float distanceBetweenTwoPoints(Point3D P1, Point3D P2);
private:
    Point3D result;
};

#endif // UNITVECTOR_H
