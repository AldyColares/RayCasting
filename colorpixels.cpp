#include "colorpixels.h"

ColorPixels::ColorPixels()
{
    gridPixel = new GridPixel();
}


GridPixel* ColorPixels::caluletionColorPixels(int pixelRateHorizontal,
                                              int pixelRateVertical, Scenario *scenario)

{

    camera = scenario->getCamera();
    Point3D vertexPixel;

    int heighScreen, widthScreen;
    widthScreen = camera->getWidthScreen();
    heighScreen = camera->getHeighScreen();


    Pixel pixel;
    float deltaX, deltaY;
    //zc = camera.getCameraCoordenadaZ();
    deltaY = heighScreen / pixelRateVertical;
    deltaX = widthScreen / pixelRateHorizontal;
    face3D face;
    FaceFurtherNear* faceFurtherNear = new FaceFurtherNear();

    for (int i = 0; i <= pixelRateHorizontal ; ++i) {
        for (int j = 0; j <= pixelRateVertical; ++j) {

            vertexPixel.x = -widthScreen / 2 + deltaX / 2 + (deltaX * j);
            vertexPixel.y =  heighScreen / 2 - deltaY / 2 - (deltaY * i);
            vertexPixel.z = -4;
            face = faceFurtherNear->lookUpSmallestDistanceFace(vertexPixel, scenario->getMaterial());


            if (face.chosenFaceFlag == true){
                face.chosenFaceFlag = false;

                pixel.red   = convertColorForFormatRGB32(0.4);
                pixel.green = convertColorForFormatRGB32(0.4);
                pixel.blue  = convertColorForFormatRGB32(0.4);
                gridPixel->setColorPixel(i, j, pixel);

            }

        }
    }
    return gridPixel;
}

light ColorPixels::ambientColor(light light0, propertyMaterial proMat)
{
    light IAmb;
    IAmb.red = light0.red * proMat.materialAmbientRed;
    IAmb.green = light0.green * proMat.materialAmbientGreen;
    IAmb.blue = light0.blue * proMat.materialAmbientBlue;
    return IAmb;
}

light ColorPixels::diffuseColor()
{

}

light ColorPixels::specularColor()
{

}

int ColorPixels::convertColorForFormatRGB32(float color)
{
    if (color >= 0 && color <= 1){
        int color8bits = 255;
        return color * color8bits;
    }else{
        std::cout << "Class colorPixels: Deu problema color" << color;
    }
}


Point3D ColorPixels::calculeteVectorV()
{

}
