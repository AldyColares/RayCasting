#include "scalerobject.h"

ScalerObject::ScalerObject()
{

}

void ScalerObject::scaler(Point3D valueScaler, ScenarioObject *scenarioObject)
{
    centroid = scenarioObject->getCentroid();
    // Taking the vertices for the center of the world.
    centroid.x *= -1;
    centroid.y *= -1;
    centroid.z *= -1;
    translationObject.moveObjectScaler(scenarioObject, centroid);

    sizeVertex = scenarioObject->getSizeVector();
    for (int i = 1; i <= sizeVertex; ++i){
        NthVertex = scenarioObject->getVectorObjIn3D(i);
        auxVertex = matrixScaler(NthVertex, valueScaler);
        listVectores.push_back(auxVertex);
    }
    scenarioObject->setListVertex(listVectores);
    centroid.x *= -1;
    centroid.y *= -1;
    centroid.z *= -1;
    translationObject.moveObjectScaler(scenarioObject, centroid);

    listVectores.clear();
}

Point3D ScalerObject::matrixScaler(Point3D NthVertex, Point3D valueScaler)
{
    auxVertex.x = NthVertex.x *= valueScaler.x;
    auxVertex.y = NthVertex.y *= valueScaler.y;
    auxVertex.z = NthVertex.z *= valueScaler.z;

    return auxVertex;
}
