#include "coordinatetransformation.h"
CoordinateTransformation::CoordinateTransformation()
{



}

float *CoordinateTransformation::coordinateTransformationbyWorldForView(float vectObj[4], float vectPosView[4][4])
{
    float result[4];

    result[0] = vectPosView[0][0] * vectObj[0] + vectPosView[0][1] * vectObj[1] + vectPosView[0][2] * vectObj[2];
    result[1] = vectPosView[1][0] * vectObj[0] + vectPosView[1][1] * vectObj[1] + vectPosView[1][2] * vectObj[2];
    result[2] = vectPosView[2][0] * vectObj[0] + vectPosView[2][1] * vectObj[1] + vectPosView[2][2] * vectObj[2];
    result[3] = 1;
    return result;
}

float *CoordinateTransformation::coordinateTransformationbyViewForWorld(float vextObj[4], float vectPosVIew[4][4])
{
    float result[4];

    return result;
}




