#include "unitvector.h"

UnitVector::UnitVector()
{

}

point3D UnitVector::normalize(point3D v1)
{
    point3D result;
    float aux = sqrt(pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
    result.x = v1.x/aux;
    result.y = v1.y/aux;
    result.z = v1.z/aux;

    return result;
}
