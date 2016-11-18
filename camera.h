#ifndef CAMERA_H
#define CAMERA_H

#include "point3d.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;


class Camera
{
public:
    Camera();
    void loadCamera();
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
	    upJCamera, upKcamera, lookAt, near, far;

    int heighScreen, widthScreen;
    string sub;

};

#endif // CAMERA_H
