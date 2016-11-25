#ifndef SCENARIOOBJECT_H
#define SCENARIOOBJECT_H
#include "face3d.h"
#include "point3d.h"
#include "vector"
#include "propertymaterial.h"
#include <string>

class ScenarioObject
{
public:
    ScenarioObject();
    std::string nameObject;

   void setFaceObjIn3D(face3D face);
   void setListFaces(std::vector<face3D> facesObjIn3D);
   void setVectorObjIn3D(float point[3]);
   void setListVertex(std::vector<Point3D> listVectores);
   void setSizeFaces(int sizeFaces);
   void setSizeVector(int sizeVector);
   void setNameObject(std::string nameObject);
   void setPropertyMaterial(propertyMaterial propMat);

   face3D getFaceObjIn3D(int position);
   Point3D getVectorObjIn3D(int position);
   propertyMaterial getPropertyMaterial();

   int getSizeFaces();
   int getSizeVector();


   propertyMaterial propMat;


private:
    std::vector<face3D> facesObjIn3D;
    std::vector<Point3D> listVectores;
    int sizeFaces;
    int sizeVector;
    int x = 0;
    int y = 1;
    int z = 2;


};
#endif // SCENARIOOBJECT_H
