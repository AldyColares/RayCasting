#include "crossproduct.h"
#include <math.h>

CrossProduct::CrossProduct()
{

}

point3D CrossProduct::crossProduct(point3D v1, point3D v2)
{
    // x == 0; y == 1; z == 2; v1;v2
     point3D result;
     result.x = v1.y * v2.z - v1.z * v2.y;
     result.y = v1.z * v2.x - v1.x * v2.z;
     result.z = v1.x * v2.y - v1.y * v2.x;
     return unitVector(result);
}

point3D CrossProduct::unitVector(point3D v1)
{
       point3D result;
       float aux = sqrt(pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
       result[0] = v1.x/aux;
       result[1] = v1.y/aux;
       result[2] = v1.z/aux;

       return result;

}
