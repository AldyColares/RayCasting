#ifndef CAMERA_H
#define CAMERA_H

#include "point3d.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>

class Camera
{
public:
    Camera();
    void loadCamera();
    point3D getUpICamera();
    point3D getUpJCamera();
    point3D getUpKCamera();
    point3D getEye();
    point3D getLoakAt();
    point3D getCenterCamera();
    point3D getNear();
    point3D getFar();
    int getHeighScreen();
    int getWidthScreen();

private:
    point3D eye, centerCamera, upICamera,  
	    upJCamera, upKcamera, lookAt, near, far;

    int heighScreen, widthScreen;

};

#endif // CAMERA_H
