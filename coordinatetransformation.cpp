#include "coordinatetransformation.h"


CoordinateTransformation::CoordinateTransformation()
{

}

ScenarioObject *CoordinateTransformation::coordinateTransformationbyWorldForCamera

(ScenarioObject *scenarioObject,
 Camera *camera)

{
    int amountVector = scenarioObject->getSizeVector();

    eye = camera->getEye();
    i = camera->getUpICamera();
    j = camera->getUpJCamera();
    k = camera->getUpKCamera();

    ScenarioObject* scenarioObjectTransformCoordCamera = new ScenarioObject();
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

ScenarioObject *CoordinateTransformation::coordinateTransformationbyCameraForWorld(
        ScenarioObject *scenarioObject, Camera *camera)

// inacabado
{
    Point3D i, j, k, eye;
    i = camera->getUpICamera();
    j = camera->getUpJCamera();
    k = camera->getUpKCamera();
    eye = camera->getEye();
}

