#ifndef SCALEROBJECT_H
#define SCALEROBJECT_H
#include "point3d.h"
#include "scenarioObject.h"
#include "translationobject.h"
#include "generatevetor.h"

class ScalerObject
{
public:
    ScalerObject();
    void scaler(Point3D valueScaler, ScenarioObject* scenarioObject);
    Point3D matrixScaler(Point3D NthVertex, Point3D valueScaler);
private:
    int sizeVertex;
    Point3D NthVertex, auxVertex, centroid, VertexOring;
    std::vector<Point3D> listVectores;
    TranslationObject translationObject;
    GenerateVetor generateVetor;
};

#endif // SCALEROBJECT_H
