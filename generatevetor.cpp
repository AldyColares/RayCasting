#include "generatevetor.h"

GenerateVetor::GenerateVetor()
{

}

Point3D GenerateVetor::generateVector(Point3D V1, Point3D V2)
{
    resultVector.x = V2.x - V1.x;
    resultVector.y = V2.y - V1.y;
    resultVector.z = V2.z - V1.z;
    resultVector.w = 0;
    return resultVector;
}
