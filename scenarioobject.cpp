#include "scenarioObject.h"

ScenarioObject::ScenarioObject()
{

}

void ScenarioObject::setFaceObjIn3D(face3D face)
{
    facesObjIn3D.push_back(face);
    setSizeFaces(facesObjIn3D.size());
}

void ScenarioObject::setVectorObjIn3D(float point[3], int position)
{
    listVectores[position][x] = point[x];
    listVectores[position][y] = point[y];
    listVectores[position][z] = point[z];

}

void ScenarioObject::setSizeFaces(int sizeFaces)
{
    this->sizeFaces = sizeFaces;
}

void ScenarioObject::setSizeVector(int sizeVector)
{
    this->sizeVector = sizeVector;
}

face3D ScenarioObject::getFaceObjIn3D(int position)
{
    return facesObjIn3D[position];
}

Point3D ScenarioObject::getVectorObjIn3D(int position)
{
    position -= 1;
    Point3D point;
    point.x = listVectores[position][x];
    point.y = listVectores[position][y];
    point.z = listVectores[position][z];

    return point;
}


int ScenarioObject::getSizeFaces()
{
    return sizeFaces;
}

int ScenarioObject::getSizeVector()
{
    return sizeVector;
}



