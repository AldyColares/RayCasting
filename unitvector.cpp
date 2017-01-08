#include "unitvector.h"

UnitVector::UnitVector()
{

}

Point3D UnitVector::normalize(Point3D v1)
{
    float aux = sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z));
    if(aux != 0 ){
        result.x = v1.x/aux;
        result.y = v1.y/aux;
        result.z = v1.z/aux;
    }else{
        result.x = 0;
        result.y = 0;
        result.z = 0;
    }
    return result;
}

float UnitVector::distanceBetweenTwoPoints(Point3D P1, Point3D P2)
{
    return sqrt( pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2) + pow(P2.z - P1.z, 2));
}
