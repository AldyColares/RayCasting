#ifndef SCENARIOOBJECT_H
#define SCENARIOOBJECT_H
#include "face3d.h"
#include "point3d.h"
const int x = 0;
const int y = 1;
const int z = 2;

class ScenarioObject
{
public:
    ScenarioObject();

   void setFaceObjIn3D(face3D face, int position);
   void setVectorObjIn3D(float point[3], int position);

    face3D getFaceObjIn3D(int position);
    point3D getVectorObjIn3D(int position);


private:
    face3D facesObjIn3D[100];
    float listVectores[100][3];


};

#endif // SCENARIOOBJECT_H
