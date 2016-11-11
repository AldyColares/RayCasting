#ifndef SCENARIOOBJECT_H
#define SCENARIOOBJECT_H
#include "face3d.h"
#include "point3d.h"
#include "vector"

const int x = 0;
const int y = 1;
const int z = 2;

class ScenarioObject
{
public:
    ScenarioObject();

   void setFaceObjIn3D(face3D face);
   void setVectorObjIn3D(float point[3], int position);
 //void setIdVectorface(int idvectorface, int verticeX1orX2orX3);
   void setSizeFaces(int sizeFaces);
   void setSizeVector(int sizeVector);

   face3D getFaceObjIn3D(int position);
   point3D getVectorObjIn3D(int position);
 //int getIdVectorface (int idvectorface);
   int getSizeFaces();
   int getSizeVector();

private:
    std::vector<face3D> facesObjIn3D;
    float listVectores[100][3];
    int sizeFaces;
    int sizeVector;

};
#endif // SCENARIOOBJECT_H
