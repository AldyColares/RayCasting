#ifndef COORDINATETRANSFORMATION_H
#define COORDINATETRANSFORMATION_H
#include "scenarioObject.h"
#include "dot.h"
#include "point3d.h"
#include "camera.h"
#include <vector>
#include "scenarioObject.h"
#include "scenario.h"


class CoordinateTransformation
{
public:
    CoordinateTransformation();
    void coordinateTransformationbyWorldForCamera(Scenario *scenario);
    void coordinateTransformationbyCameraForWorld(Scenario *scenario);

private:
    ScenarioObject scenarioObjectAUX;
    Dot dot;
    Point3D i, j, k, eye;
    Point3D NthVec;
    Camera* camera;
    ScenarioObject* scenarioObject;
    vector<ScenarioObject*> *vectorMaterial;


};

#endif // COORDINATETRANSFORMATION_H
