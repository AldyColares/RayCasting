#ifndef COLORPIXELS_H
#define COLORPIXELS_H
#include "pixel.h"
#include "camera.h"
#include "scenario.h"
#include "scenarioObject.h"
#include "point3d.h"
#include "facefurthernear.h"
#include "unitvector.h"
#include "generatevetor.h"
#include <string>

class ColorPixels
{
public:
    ColorPixels();
    Pixel *caluletioncolorPixels(int pixelRateHorizontal,int pixelRateVertical,
                                 Scenario scenario);
    FaceFurtherNear faceFurtherNear;
    float* calculeteVectorV();
    float* ambientColor();
    float* diffuseColor();
    float* specularColor();

private:
    int convertColorForFormatRGB32(float color);
};

#endif // COLORPIXELS_H
