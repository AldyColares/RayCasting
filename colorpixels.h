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
#include "light.h"
#include "dot.h"
#include <string>
#include <stdlib.h>


class ColorPixels
{
public:
    ColorPixels();
    GridPixel* caluletionColorPixels(int pixelRateHorizontal,int pixelRateVertical, Scenario* scenario);
    Point3D calculeteVectorV();
    light ambientColor(face3D face);
    light diffuseColor(face3D face);
    light specularColor(face3D face);
    void normalizePixel(int pixelRateHorizontal , int pixelRateVertical);
private:
    int convertColorForFormatRGB32(float color);
    Camera* camera;
    GridPixel* gridPixel;
    propertyMaterial proMat;
    light light0;
    Dot dot;
};

#endif // COLORPIXELS_H
