#ifndef COLORPIXELS_H
#define COLORPIXELS_H
#include "pixel.h"
#include "gridpixel.h"
#include "camera.h"
#include "scenario.h"
#include "scenarioObject.h"
#include "point3d.h"
#include "facefurthernear.h"
#include "unitvector.h"
#include "generatevetor.h"
#include "facefurthernear.h"
#include "propertymaterial.h"
#include <string>
#include <stdlib.h>


class ColorPixels
{
public:
    ColorPixels();
    GridPixel caluletionColorPixels(int pixelRateHorizontal,int pixelRateVertical, Scenario scenario);
    Point3D calculeteVectorV();
    light ambientColor(light light0, propertyMaterial proMat);
    light diffuseColor();
    light specularColor();

private:
    int convertColorForFormatRGB32(float color);
};

#endif // COLORPIXELS_H
