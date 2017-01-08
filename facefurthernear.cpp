
#include "facefurthernear.h"

FaceFurtherNear::FaceFurtherNear()
{

}

bool FaceFurtherNear::CheakPointWithinTriangle(face3D face, Point3D Q)
{

    Point3D E,G,F,Ne;
    float result;
    for (int i = 0; i < 3; ++i) {
        if (i == 0) {
            E = generateVetor.generateVector(face.Vertex2, face.Vertex1);
            F = generateVetor.generateVector(face.Vertex3, face.Vertex1);
            G = generateVetor.generateVector(     Q      , face.Vertex1);

        }else if (i == 1){
            E = generateVetor.generateVector(face.Vertex3, face.Vertex2);
            F = generateVetor.generateVector(face.Vertex1, face.Vertex2);
            G = generateVetor.generateVector(     Q      , face.Vertex2);

        }else if(i == 2){
            E = generateVetor.generateVector(face.Vertex1, face.Vertex3);
            F = generateVetor.generateVector(face.Vertex2, face.Vertex3);
            G = generateVetor.generateVector(     Q      , face.Vertex3);
        }

        if(face.normal.x == 0 && face.Vertex1.x == 0 &&
                face.Vertex2.x == 0 && face.Vertex3.x == 0 && Q.x == 0 ){
            Ne.z = E.y * -1;
            Ne.y = E.z;
            Ne.x = 0.0000;
        }else if(face.normal.y == 0 && face.Vertex1.y == 0 &&
                 face.Vertex2.y == 0 && face.Vertex3.y == 0 && Q.y == 0){
            Ne.x = E.z * -1;
            Ne.z = E.x;
            Ne.y = 0.0000;
        }else if(face.normal.z == 0 && face.Vertex1.z == 0 &&
                 face.Vertex2.z == 0 && face.Vertex3.z == 0 && Q.z == 0) {
            Ne.x = E.y * -1;
            Ne.y = E.x;
            Ne.z = 0.0000;
        }else{
        }
        result = dot.scalarproduct(Ne, F) * dot.scalarproduct(Ne, G);
        if (result < 0.00000){
            return false;
        }
    }
    //cout << "achou!!";
    return true;
}

float FaceFurtherNear::calculeteVariavelD(Point3D normal, Point3D v1Face)
{
    float D;

    normal.x = normal.x * -1;
    normal.y = normal.y * -1;
    normal.z = normal.z * -1;

    D = dot.scalarproduct(normal, v1Face);
    return D;
}

face3D FaceFurtherNear::deleteInModuleTheLargestVertex(face3D face, Point3D &point)
{

    float moduleX, moduleY , moduleZ;
    moduleX = face.normal.x * face.normal.x;
    moduleY = face.normal.y * face.normal.y;
    moduleZ = face.normal.z * face.normal.z;
    // now, cleared the large vextex.
    if (moduleX >= moduleY){
        if(moduleX >= moduleZ){
            face.normal.x = 0.0000;
            face.Vertex1.x = 0.0000;
            face.Vertex2.x = 0.0000;
            face.Vertex3.x = 0.0000;
            point.x = 0.0000;

        }else{
            face.normal.z = 0.0000;
            face.Vertex1.z = 0.0000;
            face.Vertex2.z = 0.0000;
            face.Vertex3.z = 0.0000;
            point.z = 0.0000;

        }
    }else if(moduleY >= moduleZ){
        face.normal.y = 0.0000;
        face.Vertex1.y = 0.0000;
        face.Vertex2.y = 0.0000;
        face.Vertex3.y = 0.0000;
        point.y = 0.0000;

    }else{
        face.normal.z = 0.0000;
        face.Vertex1.z = 0.0000;
        face.Vertex2.z = 0.0000;
        face.Vertex3.z = 0.0000;
        point.z = 0.0000;

    }
    return face;
}

face3D FaceFurtherNear::lookUpSmallestDistanceFace(Point3D vectorXAndYCoordinatePixel,
                                                   vector<ScenarioObject*> *groupScenarioObject)
{
    ScenarioObject* scenarioObject;
    int leghtMaterial = groupScenarioObject->size();

    face3D Nthface, faceLessDistancia;
    float Tint, lessDistanceBetweenScreenAndFace;
    Point3D vectex1Face, auxCoordinatePIxel;

    lessDistanceBetweenScreenAndFace = std::numeric_limits<float>::max();
    for (int NthMaterial = 0; NthMaterial < leghtMaterial; ++NthMaterial) {
        scenarioObject = groupScenarioObject->at(NthMaterial);
        int leghtface = scenarioObject->getSizeFaces();

        for (int idFace = 0; idFace < leghtface; ++idFace) {
            Nthface = scenarioObject->getFaceObjIn3D(idFace);

            vectex1Face = scenarioObject->getVectorObjIn3D(Nthface.idV1);

            auxCoordinatePIxel = vectorXAndYCoordinatePixel;

            // Tint: distance in between screen of the projection and Nth face.
            Tint =  dot.scalarproduct(vectex1Face, Nthface.normal)
                    /
                    dot.scalarproduct(auxCoordinatePIxel, Nthface.normal);

            if (Tint > 0.0000){
                auxCoordinatePIxel.x *= Tint;
                auxCoordinatePIxel.y *= Tint;
                auxCoordinatePIxel.z *= Tint;

                Nthface.Vertex1 = scenarioObject->getVectorObjIn3D(Nthface.idV1);
                Nthface.Vertex2 = scenarioObject->getVectorObjIn3D(Nthface.idV2);
                Nthface.Vertex3 = scenarioObject->getVectorObjIn3D(Nthface.idV3);
                Nthface = deleteInModuleTheLargestVertex(Nthface, auxCoordinatePIxel);

                pointInsideFace = CheakPointWithinTriangle(Nthface, auxCoordinatePIxel);

                if(pointInsideFace == true && Tint < lessDistanceBetweenScreenAndFace){
                    faceLessDistancia.chosenFaceFlag = false;
                    lessDistanceBetweenScreenAndFace = Tint;
                    faceLessDistancia = scenarioObject->getFaceObjIn3D(idFace);
                    faceLessDistancia.chosenFaceFlag = true;
                    faceLessDistancia.pointInsertFace = auxCoordinatePIxel;
                    faceLessDistancia.propMaterial = scenarioObject->getPropertyMaterial();

                }

            }
        }
    }

    return faceLessDistancia;
}

bool FaceFurtherNear::checkIfThereFaceBetweenPointAndLight(face3D faceBelongPoint,
                                                           vector<ScenarioObject *> *groupScenarioObject)
{
    ScenarioObject* scenarioObject;
    float rateRemoteness = 0.0125;
    int amountMaterial = groupScenarioObject->size();
    face3D Nthface;
    float Tint, distanceBetweenPointAndLight,
            distanceBetweenPointAndNthFace, testIfdoNotZero;
    Point3D vectex1Face, vectorBetweenPointAndCoordinateLight
            ,vectorBetweenVertex1AndPoint, coordLight0, pointInsertFace, shadowRay;

    pointInsertFace = faceBelongPoint.pointInsertFace;
    //pointInsertFace.x += (rateRemoteness * faceBelongPoint.normal.x);
    //pointInsertFace.y += (rateRemoteness * faceBelongPoint.normal.y);
    //pointInsertFace.z += (rateRemoteness * faceBelongPoint.normal.z);
    coordLight0.x = faceBelongPoint.light0.x;
    coordLight0.y = faceBelongPoint.light0.y;
    coordLight0.z = faceBelongPoint.light0.z;
    distanceBetweenPointAndLight = unitVector.distanceBetweenTwoPoints(pointInsertFace, coordLight0);

    for (int NthMaterial = 0; NthMaterial < amountMaterial; ++NthMaterial) {
        scenarioObject = groupScenarioObject->at(NthMaterial);
        int amountface = scenarioObject->getSizeFaces();

        for (int idFace = 0; idFace < amountface; ++idFace) {
            Nthface = scenarioObject->getFaceObjIn3D(idFace);

            shadowRay = generateVetor.generateVector(pointInsertFace, coordLight0);
            //shadowRay.x += pointInsertFace.x;
            //shadowRay.y += pointInsertFace.y;
            //shadowRay.z += pointInsertFace.z;
            //shadowRay = unitVector.normalize(shadowRay);
            shadowRay.w = 0;

            vectex1Face = scenarioObject->getVectorObjIn3D(Nthface.idV1);
            vectorBetweenVertex1AndPoint = generateVetor.generateVector(pointInsertFace, vectex1Face);
            //vectorBetweenVertex1AndPoint = unitVector.normalize(vectorBetweenVertex1AndPoint);
            // Tint: distance in between point insert face and Nth face.
            testIfdoNotZero = dot.scalarproduct(shadowRay, Nthface.normal);

            if(testIfdoNotZero != 0.000){
                Tint =  dot.scalarproduct(vectorBetweenVertex1AndPoint, Nthface.normal)
                                                    /
                                               testIfdoNotZero;

                if (Tint > 0.0000 && Tint < 1.0){
                    shadowRay.x *= Tint;
                    shadowRay.y *= Tint;
                    shadowRay.z *= Tint;

                    Nthface.Vertex1 = scenarioObject->getVectorObjIn3D(Nthface.idV1);
                    Nthface.Vertex2 = scenarioObject->getVectorObjIn3D(Nthface.idV2);
                    Nthface.Vertex3 = scenarioObject->getVectorObjIn3D(Nthface.idV3);
                    Nthface = deleteInModuleTheLargestVertex(Nthface, shadowRay);

                    pointInsideFace = CheakPointWithinTriangle(Nthface, shadowRay);

                    if(pointInsideFace == true){
                        //cout << " é true ";

                        return true;
                    }
                }
            }

        }
    }
    return false;
}

