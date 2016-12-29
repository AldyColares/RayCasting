#ifndef FACEFURTHERNEAR_H
#define FACEFURTHERNEAR_H
#include "face3d.h"
#include "scenario.h"
#include "scenarioObject.h"
#include "point3d.h"
#include "generatevetor.h"
#include "dot.h"
#include "unitvector.h"
#include <limits>
#include <vector>

using namespace std;

class FaceFurtherNear
{
public:
    FaceFurtherNear();
    face3D lookUpSmallestDistanceFace(Point3D vectorXAndYCoordinatePixel,
                                      vector<ScenarioObject*> *groupScenarioObject);
    bool checkIfThereFaceBetweenPointAndLight(face3D faceBelongPoint,
                                       vector<ScenarioObject*> *groupScenarioObject);

private:
    UnitVector unitVector;
    GenerateVetor generateVetor;
    bool CheakPointWithinTriangle(face3D face, Point3D Q);
    float calculeteVariavelD(Point3D normal, Point3D v1Face);
    face3D deleteInModuleTheLargestVertex(face3D normal, Point3D& point);
    Dot dot;
    bool pointInsideFace;



};

#endif // FACEFURTHERNEAR_H
