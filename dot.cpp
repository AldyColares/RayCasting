#include "dot.h"

Dot::Dot()
{

}

float Dot::scalarproduct(Point3D pointV1, Point3D pointV2)
{
        float result;
        result =   pointV1.x * pointV2.x
                 + pointV1.y * pointV2.y
                 + pointV1.z * pointV2.z;
        return result;
}
