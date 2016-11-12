#include "facefurthernear.h"

FaceFurtherNear::FaceFurtherNear()
{

}

bool FaceFurtherNear::CheakPointWithinTriangle(face3D face, point3D Q)
{
    point3D E,G,F,Ne;
    float result;
    for (int i = 0; i < 3; ++i) {
        if (i == 0) {
         E = GenerateVetor.generateVector(face.Vector2, face.Vector1);
         F = GenerateVetor.generateVector(face.Vector3, face.Vector1);
         G = GenerateVetor.generateVector(    Q    , face.Vector1);

        }else if (i == 1){
         E = GenerateVetor.generateVector(face.Vector3, face.Vector2);
         F = GenerateVetor.generateVector(face.Vector1, face.Vector2);
         G = GenerateVetor.generateVector(    Q    , face.Vector2);

        }else if(i == 2){
         E = GenerateVetor.generateVector(face.Vector1, face.Vector3);
         F = GenerateVetor.generateVector(face.Vector2, face.Vector3);
         G = GenerateVetor.generateVector(    Q    , face.Vector3);

        }

        Ne.x = E.y * -1;
        Ne.y = E.x;
        result = dot.scalarproduct(Ne,F) * dot.scalarproduct(Ne, G);

        if (result < 0.00000){
            return false;
        }

    }
    return true;
}

float FaceFurtherNear::calculeteVariavelD(point3D normal, point3D verticeOneFace)
{
    float D;
    normal.x = normal.x * -1;
    normal.y = normal.y * -1;
    normal.z = normal.z * -1;
    Dot dot;
    D = dot.scalarproduct(normalInvertida, verticeOneFace);
    return D;
}

point3D FaceFurtherNear::deleteInModuleTheLargestVertex(point3D normal)
{
    float moduleX, moduleY , moduleZ;
    moduleX = normal.x * normal.x;
    moduleY = normal.y * normal.y;
    moduleZ = normal.z * normal.z;
// case that at least one vector is zero.
    if (normal.x == 0.0000){
        return normal;
    }else if(normal.y == 0.0000){
        return normal;
    }else if(normal.z == 0.0000){
        return normal;
    }
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

    normal = UnitVector.normalize(normal);
    return normal;
}

face3D FaceFurtherNear::lookUpSmallestDistanceFace(point3D pointCoordXYPixel,
                                                   ScenarioObject scenarioObject)
{
    int leghtface = scenarioObject.getSizeFaces();
    face3D Nthface, faceLessDistancia;
    Dot dot;
    float Tint, D, lessDistanceBetweenScreenAndFace;
    point3D v1Face, normalIntwoDimension;
    lessDistanceBetweenScreenAndFace = std::numeric_limits<float>::max();


    for (int idFace = 0; idFace < leghtface; ++idFace) {

        Nthface = scenarioObject.getFaceObjIn3D(idFace);
        v1Face = scenarioObject.getVectorObjIn3D(Nthface.idV1);
        D = calculeteVariavelD(Nthface.normal, v1Face);

        // Tint: distance in between screen of the projection and Nth face.
        Tint =  -1 * ( dot.scalarproduct(v1Face, Nthface.normal + D))
                                               /
                       dot.scalarproduct(pointCoordXYPixel, Nthface.normal);

        if (Tint > 0.0000){
            pointCoordXYPixel.x *= Tint;
            pointCoordXYPixel.y *= Tint;
            pointCoordXYPixel.z *= Tint;

            Nthface.Vector1 = scenarioObject.getVectorObjIn3D(Nthface.idV1);
            Nthface.Vector2 = scenarioObject.getVectorObjIn3D(Nthface.idV2);
            Nthface.Vector3 = scenarioObject.getVectorObjIn3D(Nthface.idV3);
            Nthface.normal = deleteInModuleTheLargestVertex(Nthface.normal);

            bool pointInsideFace = CheakPointWithinTriangle(Nthface, Tint);

            if(pointInsideFace == true && Tint < lessDistanceBetweenScreenAndFace){
                lessDistanceBetweenScreenAndFace = Tint;
                faceLessDistancia = scenarioObject.getFaceObjIn3D(idFace);;
            }

        }else{
            break;
        }
    }

    faceLessDistancia.chosenFaceFlag = true;
    return faceLessDistancia;
}
