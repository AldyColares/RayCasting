#ifndef GENERATENORMAL_H
#define GENERATENORMAL_H
#include "crossproduct.h"
#include "point3d.h"

class GenerateVetor
{
public:
    GenerateVetor();
    Point3D generateVector(Point3D v1, Point3D v2);

private:
    Point3D resultVector;


};

#endif // GENERATENORMAL_H
