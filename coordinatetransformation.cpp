#include "coordinatetransformation.h"


CoordinateTransformation::CoordinateTransformation()
{

}

void CoordinateTransformation::coordinateTransformationbyCameraForWorld(Scenario *scenario)

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

        for (int NthVector = 1; NthVector <= amountVector; ++NthVector) {
            NthVec = scenarioObject->getVectorObjIn3D(NthVector);

            vertexResult.x = i.x * NthVec.x + j.x * NthVec.y + k.x * NthVec.z + eye.x * NthVec.w;

            vertexResult.y = i.y * NthVec.x + j.y * NthVec.y + k.y * NthVec.z + eye.y * NthVec.w;

            vertexResult.z = i.z * NthVec.x + j.z * NthVec.y + k.z * NthVec.z + eye.z * NthVec.w;

            listVertex.push_back(vertexResult);
        }
        scenarioObject->setListVertex(listVertex);

        calculeNormal(scenarioObject);
    }
}

void CoordinateTransformation::calculeNormal(ScenarioObject *scenarioObject)
{
    int amountFaces = scenarioObject->getSizeFaces();

    listFaces.clear();
    for (int indexFaces = 0; indexFaces < amountFaces; ++indexFaces) {

        NthFace = scenarioObject->getFaceObjIn3D(indexFaces);

        vectorV1V2 = geneVetor.generateVector(scenarioObject->getVectorObjIn3D(NthFace.idV1),
                                              scenarioObject->getVectorObjIn3D(NthFace.idV2));

        vectorV2V3 = geneVetor.generateVector(scenarioObject->getVectorObjIn3D(NthFace.idV1),
                                              scenarioObject->getVectorObjIn3D(NthFace.idV3));

        NthFace.normal = crossProduct.crossProduct(vectorV1V2, vectorV2V3);
        listFaces.push_back(NthFace);
    }
    scenarioObject->setListFaces(listFaces);
}

void CoordinateTransformation::coordinateTransformationbyWorldForCamera (Scenario *scenario)
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
        listVertex.clear();
        for (int NthVector = 1; NthVector <= amountVector; ++NthVector) {

            NthVec = scenarioObject->getVectorObjIn3D(NthVector);

            vertexResult.x = i.x * NthVec.x + i.y * NthVec.y + i.z * NthVec.z +
                    NthVec.w * dot.scalarproduct(i, eye) * (-1);

            vertexResult.y = j.x * NthVec.x + j.y * NthVec.y + j.z * NthVec.z +
                    NthVec.w * dot.scalarproduct(j, eye) * (-1);

            vertexResult.z = k.x * NthVec.x + k.y * NthVec.y + k.z * NthVec.z +
                    NthVec.w * dot.scalarproduct(k, eye) * (-1);

            listVertex.push_back(vertexResult);

        }
        scenarioObject->setListVertex(listVertex);

        calculeNormal(scenarioObject);
    }
}
