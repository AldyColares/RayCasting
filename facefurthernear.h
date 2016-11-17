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

class FaceFurtherNear
{
public:
    FaceFurtherNear();
    face3D lookUpSmallestDistanceFace(Point3D pointCoordXYPixel, ScenarioObject* scenarioObject);

private:
    GenerateVetor generateVetor;
    bool CheakPointWithinTriangle(face3D face, Point3D Q);
    float calculeteVariavelD(Point3D normal, Point3D v1Face);
    Point3D deleteInModuleTheLargestVertex(Point3D normal);

};

#endif // FACEFURTHERNEAR_H
