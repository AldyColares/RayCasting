#ifndef COORDINATETRANSFORMATION_H
#define COORDINATETRANSFORMATION_H


class CoordinateTransformation
{
public:
    CoordinateTransformation();
    float* coordinateTransformationbyWorldForView(float vectObj[4], float matrixPosView[4][4]);
    float* coordinateTransformationbyViewForWorld(float vextObj[4], float matrixPosVIew[4][4]);
};

#endif // COORDINATETRANSFORMATION_H
