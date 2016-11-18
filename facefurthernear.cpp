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
            F = generateVetor.generateVector(face.Verter3, face.Vertex1);
            G = generateVetor.generateVector(     Q      , face.Vertex1);

        }else if (i == 1){
            E = generateVetor.generateVector(face.Verter3, face.Vertex2);
            F = generateVetor.generateVector(face.Vertex1, face.Vertex2);
            G = generateVetor.generateVector(     Q      , face.Vertex2);

        }else if(i == 2){
            E = generateVetor.generateVector(face.Vertex1, face.Verter3);
            F = generateVetor.generateVector(face.Vertex2, face.Verter3);
            G = generateVetor.generateVector(     Q      , face.Verter3);
        }
        if(face.normal.z == 0.0000){
            Ne.x = E.y * -1;
            Ne.y = E.x;
            Ne.z = 0.0000;
        }else if(face.normal.y == 0.0000){
            Ne.x = E.z * -1;
            Ne.z = E.x;
            Ne.y = 0.0000;
        }else if(face.normal.x == 0.0000) {
            Ne.z = E.y * -1;
            Ne.y = E.z;
            Ne.x = 0.0000;
        }else{
            // para testes. caso o método "deleteInModuleTheLargestVertex(point3D normal)" esteja bugado.
        }
        result = dot.scalarproduct(Ne, F) * dot.scalarproduct(Ne, G);
        if (result < 0.00000){
            return false;
        }
    }
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

Point3D FaceFurtherNear::deleteInModuleTheLargestVertex(Point3D normal)
{
    UnitVector unitVector;
    // case that at least one vector is zero.
    if (normal.x == 0.0000){
        return normal;
    }else if(normal.y == 0.0000){
        return normal;
    }else if(normal.z == 0.0000){
        return normal;
    }

    float moduleX, moduleY , moduleZ;
    moduleX = normal.x * normal.x;
    moduleY = normal.y * normal.y;
    moduleZ = normal.z * normal.z;

    // now, cleared the large vextex.
    if (moduleX >= moduleY){
        if(moduleX >= moduleZ){
            normal.x = 0.0000;
        }else{
            normal.z = 0.0000;
        }

    }else if(moduleY >= moduleZ){
        normal.y = 0.0000;
    }else{
        normal.z = 0.0000;
    }

    normal = unitVector.normalize(normal);
    return normal;
}

face3D FaceFurtherNear::lookUpSmallestDistanceFace(Point3D pointCoordXYPixel,
                                                   ScenarioObject *scenarioObject)
{
    int leghtface = scenarioObject->getSizeFaces();
    face3D Nthface, faceLessDistancia;
    float Tint, D, lessDistanceBetweenScreenAndFace;
    Point3D vectex1Face;

    bool pointInsideFace;

    lessDistanceBetweenScreenAndFace = std::numeric_limits<float>::max();

    for (int idFace = 0; idFace < leghtface; ++idFace) {

        Nthface = scenarioObject->getFaceObjIn3D(idFace);

        vectex1Face = scenarioObject->getVectorObjIn3D(Nthface.idV1);
        //D = calculeteVariavelD(Nthface.normal, vectex1Face);


        // Tint: distance in between screen of the projection and Nth face.
        Tint =      dot.scalarproduct(vectex1Face, Nthface.normal)
                                          /
                    dot.scalarproduct(pointCoordXYPixel, Nthface.normal);

        if (Tint > 0.0000){
            pointCoordXYPixel.x *= Tint;
            pointCoordXYPixel.y *= Tint;
            pointCoordXYPixel.z *= Tint;

            Nthface.Vertex1 = scenarioObject->getVectorObjIn3D(Nthface.idV1);
            Nthface.Vertex2 = scenarioObject->getVectorObjIn3D(Nthface.idV2);
            Nthface.Verter3 = scenarioObject->getVectorObjIn3D(Nthface.idV3);
            Nthface.normal = deleteInModuleTheLargestVertex(Nthface.normal);

            pointInsideFace = CheakPointWithinTriangle(Nthface, pointCoordXYPixel);

            if(pointInsideFace == true && Tint < lessDistanceBetweenScreenAndFace){
                faceLessDistancia.chosenFaceFlag = false;
                lessDistanceBetweenScreenAndFace = Tint;
                faceLessDistancia = scenarioObject->getFaceObjIn3D(idFace);;
                faceLessDistancia.chosenFaceFlag = true;
            }

        }
    }
    return faceLessDistancia;
}
