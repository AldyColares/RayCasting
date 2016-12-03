#include "translationobject.h"

TranslationObject::TranslationObject()
{

}

void TranslationObject::moveObject(ScenarioObject *scenarioObject, Point3D newLocationPoint)
{
    Point3D Centroid = scenarioObject->getCentroid();
    newLocationPoint = generateVetor.generateVector(Centroid, newLocationPoint);
    sweepVectexObject(scenarioObject , newLocationPoint);
}

void TranslationObject::moveObjectQuartenio(ScenarioObject *scenarioObject, Point3D newLocationPoint)
{
    sweepVectexObject(scenarioObject, newLocationPoint);
}

void TranslationObject::moveObjectScaler(ScenarioObject *scenarioObject, Point3D newLocationPoint)
{
    moveVerticesAuxiliares(scenarioObject, newLocationPoint);
    sweepVectexObject(scenarioObject, newLocationPoint);
}



void TranslationObject::sweepVectexObject(ScenarioObject *scenarioObject, Point3D newLocationPoint)
{
    sizeVertex = scenarioObject->getSizeVector();
    for (int i = 1; i <= sizeVertex; ++i) {
        NthVertex = scenarioObject->getVectorObjIn3D(i);
        auxVertex = matrixTranslation(NthVertex, newLocationPoint);

        listVectores.push_back(auxVertex);
    }
    scenarioObject->setListVertex(listVectores);
    listVectores.clear();
}

Point3D TranslationObject::matrixTranslation(Point3D newVertex, Point3D newLocationPoint)
{
    newVertex.x += newLocationPoint.x;
    newVertex.y += newLocationPoint.y;
    newVertex.z += newLocationPoint.z;

    return newVertex;
}

void TranslationObject::moveVerticesAuxiliares(ScenarioObject *scenarioObject, Point3D newLocationPoint)
{
        auxPoint = scenarioObject->getFront();
        auxPoint = matrixTranslation(auxPoint, newLocationPoint);
        scenarioObject->setFront(auxPoint);

        auxPoint = scenarioObject->getBack();
        auxPoint = matrixTranslation(auxPoint, newLocationPoint);
        scenarioObject->setBack(auxPoint);

        auxPoint = scenarioObject->getSideLeft();
        auxPoint = matrixTranslation(auxPoint, newLocationPoint);
        scenarioObject->setFront(auxPoint);

        auxPoint = scenarioObject->getSideLeft();
        auxPoint = matrixTranslation(auxPoint, newLocationPoint);
        scenarioObject->setFront(auxPoint);

        auxPoint = scenarioObject->getSideRight();
        auxPoint = matrixTranslation(auxPoint, newLocationPoint);
        scenarioObject->setSideRight(auxPoint);

        auxPoint = scenarioObject->getTop();
        auxPoint = matrixTranslation(auxPoint, newLocationPoint);
        scenarioObject->setTop(auxPoint);

        auxPoint = scenarioObject->getDown();
        auxPoint = matrixTranslation(auxPoint, newLocationPoint);
        scenarioObject->setDown(auxPoint);

}
