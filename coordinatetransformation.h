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
    ScenarioObject* coordinateTransformationbyWorldForCamera
    (ScenarioObject* scenarioObject, Camera* camera);

    ScenarioObject* coordinateTransformationbyCameraForWorld
    (ScenarioObject* scenarioObject, Camera* camera);

private:
    ScenarioObject scenarioObjectAUX;
    Dot dot;
    Point3D i, j, k, eye;
    Point3D NthVertice;


};

#endif // COORDINATETRANSFORMATION_H
