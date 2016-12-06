#ifndef QUATERNIONS_H
#define QUATERNIONS_H
#include <math.h>
#include "point3d.h"
#include "scenarioObject.h"
#include <string.h>
#include "translationobject.h"
#include "generatevetor.h"
#include "unitvector.h"
#include "crossproduct.h"

#define PI 3.14159265

using namespace std;

class Quaternions

{
public:
    Quaternions();
    void rotation(float degrees, ScenarioObject* scenarioObject, string axisQuarternios);
private:
    Point3D beginningAxisQuarternios, endAxisQuarternios, vectorAxisQuarternios,
        auxquaternios, NthVector;
    float halfCos, halfSin, x, y, z, w;
    float a, b, c;
    int sizevector;
    float MQ[4][4];
    void rotationVerticesAuxiliares(ScenarioObject* scenarioObject, string chosenDirection);
    void recalculeteNormal(ScenarioObject* scenarioObject);
    void matrizQuaternior(Point3D NthVector);
    Point3D TalkingAxisForCenterWorld(Point3D );
    void invertValuresCoordenate();
    vector<Point3D> listVertex;
    vector<face3D> listFaces;
    TranslationObject translationObject;
    GenerateVetor generateVetor;
    UnitVector unitVector;
    CrossProduct crossProduct;

    void calculeQuaternior(ScenarioObject* scenarioObject);
};

#endif // QUATERNIONS_H
