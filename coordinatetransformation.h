#ifndef COORDINATETRANSFORMATION_H
#define COORDINATETRANSFORMATION_H
#include "scenarioObject.h"
#include "dot.h"
#include "camera.h"
#include "point3d.h"


class CoordinateTransformation
{
public:
    CoordinateTransformation();
    ScenarioObject coordinateTransformationbyWorldForCamera
    (ScenarioObject scenarioObject, Camera camera);

    ScenarioObject coordinateTransformationbyCameraForWorld
    (ScenarioObject scenarioObject, Camera camera);

    float *productScalar(Camera camera);

};

#endif // COORDINATETRANSFORMATION_H
