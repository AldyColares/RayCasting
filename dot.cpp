#include "dot.h"

Dot::Dot()
{

}

float ScalarProduct::scalarproduct(float V0[3], float V1[3])
{
        float result;
        result = V0[0] * V1[0] + V0[1] * V1[1] + V0[2] * V1[2];
        return result;
}
