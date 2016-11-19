#include "camera.h"

using namespace std;

Camera::Camera()
{

}

void Camera::loadCamera(){



    ifstream infile("/home/rin/Documentos/trabalho CG/RayCasting/camera.txt");

    for(string line; getline( infile, line ); )
    {


        sub;
        istringstream iss(line);
        iss >> sub;

        if (sub.compare("eye") == 0){
            iss >> sub;
            istringstream(sub) >> eye.x;

            iss >> sub;
            istringstream(sub) >> eye.y;

            iss >> sub;
            istringstream(sub) >> eye.z;

        }else if (sub.compare("centerCamera") == 0){
            iss >> sub;
            istringstream(sub) >> centerCamera.x;

            iss >> sub;
            istringstream(sub) >> centerCamera.y;

            iss >> sub;
            istringstream(sub) >> centerCamera.z;

        }else if (sub.compare("VUp") == 0){
            iss >> sub;
            istringstream(sub) >> VUp.x;

            iss >> sub;
            istringstream(sub) >> VUp.y;

            iss >> sub;
            istringstream(sub) >> VUp.z;

        }else if (sub.compare("heighScreen") == 0){
            iss >> sub;
            istringstream(sub) >> heighScreen;

        }else if (sub.compare("widthScreen") == 0){
            iss >> sub;
            istringstream(sub) >> widthScreen;

        }else if (sub.compare("near") == 0){
            iss >> sub;
            istringstream(sub) >> near.x;

            iss >> sub;
            istringstream(sub) >> near.y;

            iss >> sub;
            istringstream(sub) >> near.z;

        }else if (sub.compare("far") == 0){
            iss >> sub;
            istringstream(sub) >> far.x;
            iss >> sub;
            istringstream(sub) >> far.y;
            iss >> sub;
            istringstream(sub) >> far.z;

        }else if (sub.compare("lookAt") == 0){
            iss >> sub;
            istringstream(sub) >> lookAt.x;
            iss >> sub;
            istringstream(sub) >> lookAt.y;
            iss >> sub;
            istringstream(sub) >> lookAt.z;
        }

    }
    calculeUp();
    infile.close();
}

void Camera::calculeUp()
{
    Point3D eyeLookAt;
    eyeLookAt = generateVetor.generateVector(eye, lookAt);
    upKcamera = unitVector.normalize(eyeLookAt);

    viewUp = generateVetor.generateVector(VUp, eye);
    upICamera =  crossProduct.crossProduct(viewUp, upKcamera);

    upJCamera = crossProduct.crossProduct(upKcamera, upICamera);

}


Point3D Camera::getCenterCamera(){
    return centerCamera;
}

Point3D Camera::getEye(){
    return eye;
}

Point3D Camera::getLoakAt(){
    return lookAt;
}

Point3D Camera::getUpICamera(){
    return upICamera;
}

Point3D Camera::getUpJCamera()
{
    return upJCamera;
}

Point3D Camera::getUpKCamera()
{
    return upKcamera;
}

Point3D Camera::getFar()
{
    return far;
}

Point3D Camera::getNear()
{
    return near;
}

int Camera::getHeighScreen()
{
    return heighScreen;
}

int Camera::getWidthScreen()
{
    return widthScreen;
}
