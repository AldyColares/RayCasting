#include "crossproduct.h"
#include <math.h>
#include "unitvector.h"

UnitVector unitVector;
CrossProduct::CrossProduct()
{

}

Point3D CrossProduct::crossProduct(Point3D v1, Point3D v2)
{
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;

    return unitVector.normalize(result);
}


