#include "colorpixels.h"
#include "unitvector.h"
#include "generatevetor.h"

UnitVector UnitVector;

ColorPixels::ColorPixels()
{

}

Pixel *ColorPixels::caluletioncolorPixels(int pixelRateHorizontal,
                                          int pixelRateVertical, Scenario scenario)
{
    scenario.LoadScenario();
    Camera camera = scenario.getCamera();
    point3D verticePixel;
    int heighScreen, widthScreen;
    widthScreen = camera.getWidthScreen();
    heighScreen = camera.getHeighScreen();


    ScenarioObject ScenarioObject = scenario.getMaterial();
    Pixel pixel[pixelRateHorizontal][pixelRateVertical];

    float deltaX, deltaY;
    //zc = camera.getCameraCoordenadaZ();
    deltaY = heighScreen / pixelRateVertical;
    deltaX = widthScreen / pixelRateHorizontal;
    for (int i = 1; i <= pixelRateHorizontal; ++i) {
        for (int j = 1; j <= pixelRateVertical; ++j) {

           verticePixel.x = -widthScreen / 2 + deltaX / 2 + (deltaY * j);
           verticePixel.y =  widthScreen / 2 - deltaX / 2 - (deltaY * i);
           verticePixel.z = -4;

        }
    }

}

void ColorPixels::loadScenario(Scenario scenario)
{
    scenario.LoadScenario();
    return scenario;
}

float *ColorPixels::ambientColor()
{

}

float *ColorPixels::diffuseColor()
{

}

float *ColorPixels::specularColor()
{

}

face3D ColorPixels::faceFurtherNear(point3D verticePixel, ScenarioObject scenarioObject)
{
    int leghtface = scenarioObject.getSizeVector();
    int positionFaceLessDistancia;
    int farProjection = -50;
    face3D Nthface;
    Dot dot;
    float Tint, D;
    point3D verticeOneFace, normalInvertida, normalIntwoDimension;
    for (int var = 0; var < leghtface; ++var) {

        Nthface = scenarioObject.getFaceObjIn3D(var);
        verticeOneFace = scenarioObject.getVectorObjIn3D(Nthface.idV1);
        D = calculeteVariavelD(Nthface.normal, verticeOneFace);

        Tint =  -1 * ( dot.scalarproduct(verticeOneFace, Nthface.normal + D))
                                               /
                       dot.scalarproduct(verticePixel, Nthface.normal);

        if (Tint > 0.0){
            verticePixel.x *= Tint;
            verticePixel.y *= Tint;
            verticePixel.z *= Tint;
            normalIntwoDimension = deleteInModuleTheLargestVertex(Nthface.normal);
        }else{
            break;
        }

    }

}

point3D ColorPixels::deleteInModuleTheLargestVertex(point3D normal)
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
        return normal.z;
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


float *ColorPixels::calculeteVectorV()
{

}

bool ColorPixels::CheakPointWithinTriangle(face3D face, point3D tint)
{
    point3D vector[3];
    for (int i = 0; i <= 3; ++i) {
         v = GenerateVetor.generateVector(face.idV1, face.idV2)
    }
}

float ColorPixels::calculeteVariavelD(point3D normal, point3D verticeOneFace)
{
    float D;
    normal.x = normal.x * -1;
    normal.y = normal.y * -1;
    normal.z = normal.z * -1;
    Dot dot;
    D = dot.scalarproduct(normalInvertida,verticeOneFace);
    return D;
}
