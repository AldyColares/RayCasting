#include "generatevetor.h"

GenerateVetor::GenerateVetor()
{

}

point3D GenerateVetor::generateVector(point3D V1, point3D V2)
{
    point3D resultVector;
    resultVector.x = V2.x - V1.x;
    resultVector.y = V2.y - V1.y;
    resultVector.z = V2.z - V1.z;
    return resultVector;
}
