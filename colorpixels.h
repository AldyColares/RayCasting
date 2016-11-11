#ifndef COLORPIXELS_H
#define COLORPIXELS_H
#include "pixel.h"
#include "camera.h"
#include "scenario.h"
#include "scenarioObject.h"
#include "point3d.h"


class ColorPixels
{
public:
    ColorPixels();
    Pixel *caluletioncolorPixels(int pixelRateHorizontal, int pixelRateVertical,
                                 Scenario scenario);
    void loadScenario(Scenario scenario);
    face3D faceFurtherNear(point3D verticePixel, ScenarioObject scenarioObject);
    bool CheakPointWithinTriangle(face3D face, point3D tint);
    float calculeteVariavelD(point3D normal, point3D verticeOneFace);
    point3D deleteInModuleTheLargestVertex(point3D normal);


    float* calculeteVectorV();
    float* ambientColor();
    float* diffuseColor();
    float* specularColor();
};

#endif // COLORPIXELS_H
