#include "unitvector.h"

UnitVector::UnitVector()
{

}

Point3D UnitVector::normalize(Point3D v1)
{
    Point3D result;
    float aux = sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z));
    result.x = v1.x/aux;
    result.y = v1.y/aux;
    result.z = v1.z/aux;

    return result;
}
