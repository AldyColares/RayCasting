#ifndef CROSSPRODUCT_H
#define CROSSPRODUCT_H
#include "point3d.h"



class CrossProduct
{
public:
    CrossProduct();
    Point3D crossProduct(Point3D v1, Point3D v2);
private:
    Point3D result;
};

#endif // CROSSPRODUCT_H
