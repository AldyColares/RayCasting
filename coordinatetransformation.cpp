#include "coordinatetransformation.h"


CoordinateTransformation::CoordinateTransformation()
{

}

ScenarioObject *CoordinateTransformation::coordinateTransformationbyWorldForCamera
(ScenarioObject *scenarioObject,
 Camera *camera)

{

    i = camera->getUpICamera();
    j = camera->getUpJCamera();
    k = camera->getUpKCamera();
    eye = camera->getEye();
    int amountVector = scenarioObject->getSizeVector();
    ScenarioObject* scenarioObjectTransformCoordCamera = new ScenarioObject();

    for (int NthVector = 1; NthVector < amountVector; ++NthVector) {
        NthVertice = scenarioObject->getVectorObjIn3D(NthVector);

        float vertResult[3];

        vertResult[0] = i.x * NthVertice.x + j.x * NthVertice.y +
                i.x * NthVertice.z + eye.x * 1;

        vertResult[1] = i.y * NthVertice.x + j.y * NthVertice.y +
                i.y * NthVertice.z + eye.y * 1;

        vertResult[2] = i.z * NthVertice.x + j.z * NthVertice.y +
                i.z * NthVertice.z + eye.z * 1;

        scenarioObjectTransformCoordCamera->setVectorObjIn3D(vertResult);

    }
    return scenarioObjectTransformCoordCamera;



}

ScenarioObject *CoordinateTransformation::coordinateTransformationbyCameraForWorld(
        ScenarioObject *scenarioObject, Camera *camera)

{


    eye = camera->getEye();
    i = camera->getUpICamera();
    j = camera->getUpJCamera();
    k = camera->getUpKCamera();

    ScenarioObject* scenarioObjectTransformCoordCamera = new ScenarioObject();
    int amountVector = scenarioObject->getSizeVector();
    for (int NthVector = 1; NthVector < amountVector; ++NthVector) {

        NthVertice = scenarioObject->getVectorObjIn3D(NthVector);

        float vertResult[3];

        vertResult[0] = i.x * NthVertice.x + i.y * NthVertice.y +
                i.z * NthVertice.z + 1   * dot.scalarproduct(i, eye) * (-1);


        vertResult[1] = j.x * NthVertice.x + j.y * NthVertice.y +
                j.z * NthVertice.z + 1   * dot.scalarproduct(j, eye) * (-1);

        vertResult[2] = k.x * NthVertice.x + k.y * NthVertice.y +
                k.z * NthVertice.z + 1   * dot.scalarproduct(k, eye) * (-1);

        scenarioObjectTransformCoordCamera->setVectorObjIn3D(vertResult);

    }
    return scenarioObjectTransformCoordCamera;

}

