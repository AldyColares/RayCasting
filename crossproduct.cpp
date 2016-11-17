#include "crossproduct.h"
#include <math.h>
#include "unitvector.h"

UnitVector unitVector;
CrossProduct::CrossProduct()
{

}

Point3D CrossProduct::crossProduct(Point3D v1, Point3D v2)
{
    // x == 0; y == 1; z == 2; v1;v2
    Point3D result;
    result.x =       v1.y * v2.z - v1.z * v2.y;
    result.y = -1 * (v1.z * v2.x - v1.x * v2.z);
    result.z =       v1.x * v2.y - v1.y * v2.x;
    return unitVector.normalize(result);
}

