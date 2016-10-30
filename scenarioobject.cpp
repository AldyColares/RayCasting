#include "scenarioObject.h"

ScenarioObject::ScenarioObject()
{

}

void ScenarioObject::setFaceObjIn3D(face3D face, int position)
{
    facesObjIn3D[position].v1 = face.v1;
    facesObjIn3D[position].v2 = face.v2;
    facesObjIn3D[position].v3 = face.v3;
    facesObjIn3D[position].normal = face.normal;

}

void ScenarioObject::setVectorObjIn3D(float point[3], int position)
{
    listVectores[position][x] = point[x];
    listVectores[position][y] = point[y];
    listVectores[position][z] = point[z];

}

face3D ScenarioObject::getFaceObjIn3D(int position)
{
    face3D face;
    face = facesObjIn3D[position];

    return face;
}

point3D ScenarioObject::getVectorObjIn3D(int position)
{
    point3D point;
    point.x = listVectores[position][x];
    point.y = listVectores[position][y];
    point.z = listVectores[position][z];

    return point;

}


