#include "scenarioobject.h"

ScenarioObject::ScenarioObject()
{

}

ScenarioObject::setFaceObjIn3D(face3D listVecOfface, int position)
{
    this->facesObjIn3D[position].v1 = listVecOfface.v1;
    this->facesObjIn3D[position].v2 = listVecOfface.v2;
    this->facesObjIn3D[position].v3 = listVecOfface.v3;
    this->facesObjIn3D[position].normal = listVecOfface.normal;

}

ScenarioObject::setVectorObjIn3D(float point[3], int position)
{
    this->listVectores[position][x] = point[x];
    this->listVectores[position][y] = point[y];
    this->listVectores[position][z] = point[z];

}

face3D ScenarioObject::getFaceObjIn3D(int position)
{
    face3D face;
    face = facesObjIn3D(position);

    return face;
}

point3D ScenarioObject::getVectorObjIn3D(int position)
{
    listVecOfface point;
    point.x = listVectores[position][x];
    point.y = listVectores[position][y];
    point.z = listVectores[position][z];

    return point;

}


