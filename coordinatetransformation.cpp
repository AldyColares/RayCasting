#include "coordinatetransformation.h"


CoordinateTransformation::CoordinateTransformation()
{

}

ScenarioObject CoordinateTransformation::coordinateTransformationbyWorldForCamera
                                        (ScenarioObject scenarioObject, Camera camera)
{
    int amountVector = scenarioObject.getSizeVector();
    ScenarioObject scenarioObjectAUX;
    Dot dot;
    point3D i, j, k, eye;
    eye = camera.getEye();
    i = camera.getUpICamera();
    j = camera.getUpJCamera();
    k = camera.getUpKCamera();

    for (int NthVector = 0; NthVector < amountVector; ++NthVector) {

        point3D NthVertice = scenarioObject.getVectorObjIn3D(NthVector);
        float vertResult[3];

        vertResult[0] = i.x * NthVertice.x + i.y * NthVertice.y +
                        i.z * NthVertice.z + 1   * dot.scalarproduct(i, eye) * (-1);


        vertResult[1] = j.x * NthVertice.x + j.y * NthVertice.y +
                        j.z * NthVertice.z + 1   * dot.scalarproduct(j, eye) * (-1);

        vertResult[2] = k.x * NthVertice.x + k.y * NthVertice.y +
                        k.z * NthVertice.z + 1   * dot.scalarproduct(k, eye) * (-1);

        scenarioObject.setVectorObjIn3D(vertResult , NthVector);

    }
    return scenarioObjectAUX;

}

ScenarioObject CoordinateTransformation::coordinateTransformationbyCameraForWorld
                                        (ScenarioObject scenarioObject, Camera camera)
// inacabado
{
    point3D i, j, k, eye;
    i = camera.getUpICamera();
    j = camera.getUpJCamera();
    k = camera.getUpKCamera();
    eye = camera.getEye();
}

