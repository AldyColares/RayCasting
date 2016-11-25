#ifndef CAMERA_H
#define CAMERA_H

#include "point3d.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "crossproduct.h"
#include "generatevetor.h"
#include "unitvector.h"
#include "light.h"


using namespace std;

class Camera
{
public:
    Camera();
    void loadCamera();
    void calculeUp();

    light getLigth();
    Point3D getUpICamera();
    Point3D getUpJCamera();
    Point3D getUpKCamera();
    Point3D getEye();
    Point3D getLoakAt();
    Point3D getCenterCamera();
    Point3D getNear();
    Point3D getFar();
    int getHeighScreen();
    int getWidthScreen();

private:
    Point3D eye, centerCamera, upICamera,
        upJCamera, upKCamera, lookAt, near,
        far, viewUp, VUp;

    int heighScreen, widthScreen;
    light light0;
    string sub;
    UnitVector unitVector;
    GenerateVetor generateVetor;
    CrossProduct crossProduct;

};

#endif // CAMERA_H
