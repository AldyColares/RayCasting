#include "scenarioObject.h"

ScenarioObject::ScenarioObject()
{

}

void ScenarioObject::setFaceObjIn3D(face3D face)
{

    facesObjIn3D.push_back(face);
    setSizeFaces(facesObjIn3D.size());

}

void ScenarioObject::setVectorObjIn3D(float point[3])
{
    Point3D pointtmp;
    pointtmp.x = point[0];
    pointtmp.y = point[1];
    pointtmp.z = point[2];
    pointtmp.w = 1;

    listVectores.push_back(pointtmp);
    setSizeVector(listVectores.size());
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
    point = listVectores[position];
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



