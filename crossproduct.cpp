#include "crossproduct.h"
#include <math.h>

CrossProduct::CrossProduct()
{

}


float* CrossProduct::crossProduct(float V0[3], float V1[3])
{
     float result[3];
     result[0] = V0[1] * V1[2] - V0[2] * V1[1];
     result[1] = V0[2] * V1[0] - V0[0] * V1[2];
     result[2] = V0[0] * V1[1] - V0[1] * V1[0];
     return ( unitVector(result[3]) );
}

float* CrossProduct::unitVector(float V0[3])
{
       float* result;
       float aux = sqrt(pow(V0[0],2) + pow(V0[1],2) + pow(V0[2],2));
       result[0] = V0[0]/aux;
       result[1] = V0[1]/aux;
       result[2] = V0[2]/aux;

       return result;

}
