#ifndef TRANSLATIONOBJECT_H
#define TRANSLATIONOBJECT_H
#include "scenarioObject.h"
#include "point3d.h"
#include "generatevetor.h"

class TranslationObject
{
public:
    TranslationObject();
    void sweepVectexObject(ScenarioObject* scenarioObject, Point3D newLocationPoint);
    void moveObject(ScenarioObject* scenarioObject, Point3D newLocationPoint);
    void moveObjectQuartenio(ScenarioObject* scenarioObject, Point3D newLocationPoint);
    void moveObjectScaler(ScenarioObject* scenarioObject, Point3D newLocationPoint);
    void moveVerticesAuxiliares(ScenarioObject* scenarioObject, Point3D newLocationPoint);
    Point3D matrixTranslation(Point3D NthVertex, Point3D newLocationPoint);

private:
    int sizeVertex;
    Point3D NthVertex, auxVertex ,auxPoint;
    std::vector<Point3D> listVectores;

    void moveVerticesAuxiliares(ScenarioObject* scenarioObject);
    GenerateVetor generateVetor;

};

#endif // TRANSLATIONOBJECT_H
