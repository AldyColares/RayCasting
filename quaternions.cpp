#include "quaternions.h"

Quaternions::Quaternions()
{

}

void Quaternions::rotation(float degrees, ScenarioObject *scenarioObject, string axisQuarternios)
{

    if (axisQuarternios.compare("FrontEndBack") == 0){
        beginningAxisQuarternios = scenarioObject->getFront();
        endAxisQuarternios = scenarioObject->getBack();

    }else if(axisQuarternios.compare("sideLeftEndsideRight") == 0){
        beginningAxisQuarternios = scenarioObject->getSideLeft();
        endAxisQuarternios = scenarioObject->getSideRight();

    }else if(axisQuarternios.compare("TopEndDown") == 0){
        beginningAxisQuarternios = scenarioObject->getDown();
        endAxisQuarternios = scenarioObject->getTop();
    }

    vectorAxisQuarternios = generateVetor.generateVector(beginningAxisQuarternios, endAxisQuarternios);
    vectorAxisQuarternios = unitVector.normalize(vectorAxisQuarternios);

    halfCos = (cos(degrees * PI / 180.0)) / 2;
    halfSin = (sin(degrees * PI / 180.0)) / 2;

    beginningAxisQuarternios.x *= -1;
    beginningAxisQuarternios.y *= -1;
    beginningAxisQuarternios.z *= -1;

    translationObject.moveObjectQuartenio(scenarioObject, beginningAxisQuarternios);
    calculeQuaternior(scenarioObject);

    beginningAxisQuarternios.x *= -1;
    beginningAxisQuarternios.y *= -1;
    beginningAxisQuarternios.z *= -1;
    translationObject.moveObjectQuartenio(scenarioObject, beginningAxisQuarternios);

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

        auxquaternios.x = NthVector.x * MQ[0][0] + NthVector.y * MQ[0][1] + NthVector.z * MQ[0][2];


        auxquaternios.y = NthVector.y * MQ[1][0] + NthVector.y * MQ[1][1] + NthVector.y * MQ[1][2];


        auxquaternios.z = NthVector.z * MQ[2][0] + NthVector.z * MQ[2][1] + NthVector.z * MQ[2][2];

        auxquaternios.w = NthVector.w * MQ[3][3];

        listVertex.push_back(auxquaternios);
    }
    scenarioObject->setListVertex(listVertex);
    listVertex.clear();

}
