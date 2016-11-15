#include "camera.h"

using namespace std;

Camera::Camera()
{

}

void Camera::loadCamera(){


  ifstream infile("/home/rin/Documentos/trabalho CG/RayCasting/camera.txt");

  for(string line; getline( infile, line ); )
  {
   string sub;
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

       }else if (sub.compare("upICamera") == 0){
           iss >> sub;
           istringstream(sub) >> upICamera.x;

           iss >> sub;
           istringstream(sub) >> upICamera.y;

           iss >> sub;
           istringstream(sub) >> upICamera.z;

       }else if (sub.compare("upJCamera") == 0){
           iss >> sub;
           istringstream(sub) >> upJCamera.x;

           iss >> sub;
           istringstream(sub) >> upJCamera.y;

           iss >> sub;
           istringstream(sub) >> upJCamera.z;

       }else if (sub.compare("upKcamera") == 0){
           iss >> sub;
           istringstream(sub) >> upKcamera.x;

           iss >> sub;
           istringstream(sub) >> upKcamera.y;

           iss >> sub;
           istringstream(sub) >> upKcamera.z;

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
}


point3D Camera::getCenterCamera(){
    return centerCamera;
}

point3D Camera::getEye(){
    return eye;
}

point3D Camera::getLoakAt(){
    return lookAt;
}

point3D Camera::getUpICamera(){
    return upICamera;
}

point3D Camera::getUpJCamera()
{
    return upJCamera;
}

point3D Camera::getUpKCamera()
{
    return upKcamera;
}

point3D Camera::getFar()
{
    return far;
}

point3D Camera::getNear()
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
