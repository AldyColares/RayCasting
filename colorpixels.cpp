#include "colorpixels.h"


UnitVector UnitVector;
Dot dot;

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


float *ColorPixels::ambientColor()
{

}

float *ColorPixels::diffuseColor()
{

}

float *ColorPixels::specularColor()
{

}

int ColorPixels::convertColorForFormatRGB32(float color)
{
    if (0 >= color && color <= 1){
        int color8bits = 255;
        return color * color8bits;
    }else{
        std::cout << "Deu problema color" << color;
    }
}


float *ColorPixels::calculeteVectorV()
{

}



