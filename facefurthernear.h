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
    face3D lookUpSmallestDistanceFace(point3D pointCoordXYPixel, ScenarioObject scenarioObject);

private:
    bool CheakPointWithinTriangle(face3D face, point3D Q);
    float calculeteVariavelD(point3D normal, point3D v1Face);
    point3D deleteInModuleTheLargestVertex(point3D normal);

};

#endif // FACEFURTHERNEAR_H
