#include "quaternions.h"

Quaternions::Quaternions()
{

}

void Quaternions::rotation(float degrees, ScenarioObject *scenarioObject, string axisQuarternios)
{

    if (axisQuarternios.compare("Front") == 0){
        beginningAxisQuarternios = scenarioObject->getCentroid();
        endAxisQuarternios = scenarioObject->getFront();

    }else if(axisQuarternios.compare("sideRight") == 0){
        beginningAxisQuarternios = scenarioObject->getCentroid();
        endAxisQuarternios = scenarioObject->getSideRight();

    }else if(axisQuarternios.compare("Top") == 0){
        beginningAxisQuarternios = scenarioObject->getCentroid();
        endAxisQuarternios = scenarioObject->getTop();
    }

    vectorAxisQuarternios = generateVetor.generateVector(beginningAxisQuarternios, endAxisQuarternios);
    vectorAxisQuarternios = unitVector.normalize(vectorAxisQuarternios);

    halfCos = cos((degrees / 2) * PI / 180.0);
    halfSin = sin((degrees / 2) * PI / 180.0);

    invertValuresCoordenate();

    translationObject.moveObjectQuartenio(scenarioObject, beginningAxisQuarternios, axisQuarternios);
    calculeQuaternior(scenarioObject);

    invertValuresCoordenate();

    translationObject.moveObjectQuartenio(scenarioObject, beginningAxisQuarternios, axisQuarternios);
}

void Quaternions::invertValuresCoordenate()
{
    beginningAxisQuarternios.x *= -1;
    beginningAxisQuarternios.y *= -1;
    beginningAxisQuarternios.z *= -1;
}

void Quaternions::calculeQuaternior(ScenarioObject *scenarioObject)
{
    x = halfSin * vectorAxisQuarternios.x;
    y = halfSin * vectorAxisQuarternios.y;
    z = halfSin * vectorAxisQuarternios.z;
    w = halfCos;

    sizevector = scenarioObject->getSizeVector();
    // MQ: Matriz quaternior.
    MQ[0][0] = w*w + x*x - y*y - z*z;
    MQ[0][1] = 2*x*y - 2*w*z;
    MQ[0][2] = 2*x*z + 2*w*y;

    MQ[1][0] = 2*x*y + 2*w*z;
    MQ[1][1] = w*w - x*x + y*y - z*z;
    MQ[1][2] = 2*y*z - 2*w*x;

    MQ[2][0] = 2*x*z - 2*w*y;
    MQ[2][1] = 2*y*z + 2*w*x;
    MQ[2][2] = w*w - x*x - y*y + z*z;

    MQ[3][3] = w*w + x*x + y*y + z*z;

    for (int i = 1; i <= sizevector; ++i) {
        NthVector = scenarioObject->getVectorObjIn3D(i);
        matrizQuaternior(NthVector);

        listVertex.push_back(auxquaternios);
    }
    scenarioObject->setListVertex(listVertex);
    recalculeteNormal(scenarioObject);

    listVertex.clear();
}

void Quaternions::matrizQuaternior(Point3D NthVector)
{
    auxquaternios.x = NthVector.x * MQ[0][0] + NthVector.y * MQ[0][1] + NthVector.z * MQ[0][2];
    auxquaternios.y = NthVector.x * MQ[1][0] + NthVector.y * MQ[1][1] + NthVector.z * MQ[1][2];
    auxquaternios.z = NthVector.x * MQ[2][0] + NthVector.y * MQ[2][1] + NthVector.z * MQ[2][2];
    auxquaternios.w = NthVector.w * MQ[3][3];
}

void Quaternions::rotationVerticesAuxiliares(ScenarioObject *scenarioObject, string chosenDirection)
{
    Point3D auxPoint;
    if(chosenDirection.compare("Front") == 0){
        auxPoint = scenarioObject->getSideRight();
        matrizQuaternior(auxPoint);
        scenarioObject->setSideRight(auxquaternios);

        auxPoint = scenarioObject->getTop();
        matrizQuaternior(auxPoint);
        scenarioObject->setTop(auxquaternios);

    }else if(chosenDirection.compare("sideRight") == 0){
        auxPoint = scenarioObject->getFront();
        matrizQuaternior(auxPoint);
        scenarioObject->setFront(auxquaternios);;

        auxPoint = scenarioObject->getTop();
        matrizQuaternior(auxPoint);
        scenarioObject->setTop(auxquaternios);

    }else if(chosenDirection.compare("Top") == 0){
        auxPoint = scenarioObject->getFront();
        matrizQuaternior(auxPoint);
        scenarioObject->setFront(auxquaternios);

        auxPoint = scenarioObject->getSideRight();
        matrizQuaternior(auxPoint);
        scenarioObject->setSideRight(auxquaternios);
    }
}

void Quaternions::recalculeteNormal(ScenarioObject *scenarioObject)
{
    face3D vectorsFace;
    Point3D vectorV1V2, vectorV2V3, auxpoint;
    int sizeFace = scenarioObject->getSizeFaces();
    for (int i = 0; i < sizeFace; ++i) {
        vectorsFace = scenarioObject->getFaceObjIn3D(i);

        vectorV1V2 = generateVetor.generateVector(scenarioObject->getVectorObjIn3D(vectorsFace.idV1),
                                                  scenarioObject->getVectorObjIn3D(vectorsFace.idV2));

        vectorV2V3 = generateVetor.generateVector(scenarioObject->getVectorObjIn3D(vectorsFace.idV1),
                                                  scenarioObject->getVectorObjIn3D(vectorsFace.idV3));

        auxpoint = crossProduct.crossProduct(vectorV1V2, vectorV2V3);
        vectorsFace.normal = auxpoint;
        listFaces.push_back(vectorsFace);
    }
    scenarioObject->setListFaces(listFaces);
    listFaces.clear();

}
