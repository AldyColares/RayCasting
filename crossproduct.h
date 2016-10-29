#ifndef CROSSPRODUCT_H
#define CROSSPRODUCT_H
#include "point3d.h"



class CrossProduct
{
public:
    CrossProduct();
    point3D crossProduct(point3D v1, point3D v2);
    point3D unitVector(point3D v1);

};

#endif // CROSSPRODUCT_H
