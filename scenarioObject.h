#ifndef SCENARIOOBJECT_H
#define SCENARIOOBJECT_H
#include "face3d.h"
#include "point3d.h"
#include "vector"
#include "propertymaterial.h"

class ScenarioObject
{
public:
    ScenarioObject();

   void setFaceObjIn3D(face3D face);
   void setVectorObjIn3D(float point[3]);
   void setSizeFaces(int sizeFaces);
   void setSizeVector(int sizeVector);


   face3D getFaceObjIn3D(int position);
   Point3D getVectorObjIn3D(int position);

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
