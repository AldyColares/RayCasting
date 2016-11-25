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
    GenerateVetor geneVetor;
    CrossProduct crossProduct;
    ScenarioObject* scenarioObject;
    vector<ScenarioObject*> *vectorMaterial;
    vector<Point3D> listVertex;
    Point3D vertexResult;
    void calculeNormal(ScenarioObject *sceOnj);
    vector<face3D> listFaces;
    face3D NthFace;
    Point3D vectorV1V2, vectorV2V3;

};

#endif // COORDINATETRANSFORMATION_H
