#include "coordinatetransformation.h"


CoordinateTransformation::CoordinateTransformation()
{

}

void CoordinateTransformation::coordinateTransformationbyWorldForCamera(Scenario *scenario)

{
    vectorMaterial = scenario->getGroupScenarioObject();

    camera = scenario->getCamera();
    i = camera->getUpICamera();
    j = camera->getUpJCamera();
    k = camera->getUpKCamera();
    eye = camera->getEye();

    int amountMaterial = vectorMaterial->size();
    for (int NthMaterial = 0; NthMaterial < amountMaterial; ++NthMaterial) {

        scenarioObject = vectorMaterial->at(NthMaterial);

        int amountVector = scenarioObject->getSizeVector();

        for (int NthVector = 1; NthVector < amountVector; ++NthVector) {
            NthVec = scenarioObject->getVectorObjIn3D(NthVector);

            float vertResult[3];

            vertResult[0] = i.x * NthVec.x + j.x * NthVec.y + i.x * NthVec.z + eye.x * NthVec.w;

            vertResult[1] = i.y * NthVec.x + j.y * NthVec.y + i.y * NthVec.z + eye.y * NthVec.w;

            vertResult[2] = i.z * NthVec.x + j.z * NthVec.y + i.z * NthVec.z + eye.z * NthVec.w;

            scenarioObject->setVectorObjIn3D(vertResult);

        }
    }
}

void CoordinateTransformation::coordinateTransformationbyCameraForWorld (Scenario *scenario)
{
    vectorMaterial = scenario->getGroupScenarioObject();

    camera = scenario->getCamera();
    eye = camera->getEye();
    i = camera->getUpICamera();
    j = camera->getUpJCamera();
    k = camera->getUpKCamera();

    int amountMaterial = vectorMaterial->size();
    for (int NthMaterial = 0; NthMaterial < amountMaterial; ++NthMaterial) {
        scenarioObject = vectorMaterial->at(NthMaterial);

        int amountVector = scenarioObject->getSizeVector();

        for (int NthVector = 1; NthVector < amountVector; ++NthVector) {

            NthVec = scenarioObject->getVectorObjIn3D(NthVector);

            float vertResult[3];

            vertResult[0] = i.x * NthVec.x + i.y * NthVec.y + i.z * NthVec.z +
                    NthVec.w * dot.scalarproduct(i, eye) * (-1);

            vertResult[1] = j.x * NthVec.x + j.y * NthVec.y + j.z * NthVec.z +
                    NthVec.w * dot.scalarproduct(j, eye) * (-1);

            vertResult[2] = k.x * NthVec.x + k.y * NthVec.y + k.z * NthVec.z +
                    NthVec.w * dot.scalarproduct(k, eye) * (-1);

            scenarioObject->setVectorObjIn3D(vertResult);

        }
    }
}

