#include "scenarioObject.h"

ScenarioObject::ScenarioObject()
{

}

void ScenarioObject::setFaceObjIn3D(face3D face)
{

    facesObjIn3D.push_back(face);
    setSizeFaces(facesObjIn3D.size());
}

void ScenarioObject::setListFaces(std::vector<face3D> facesObjIn3D)
{
    this->facesObjIn3D.clear();
    this->facesObjIn3D = facesObjIn3D;
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

void ScenarioObject::setListVertex(std::vector<Point3D> listVectores)
{
    this->listVectores.clear();
    this->listVectores = listVectores;
    setSizeFaces(facesObjIn3D.size());
}

void ScenarioObject::setSizeFaces(int sizeFaces)
{
    this->sizeFaces = sizeFaces;
}

void ScenarioObject::setSizeVector(int sizeVector)
{
    this->sizeVector = sizeVector;
}

void ScenarioObject::setNameObject(std::string nameObject)
{
    this->nameObject = nameObject;
}

void ScenarioObject::setPropertyMaterial(propertyMaterial propMat)
{
    this->propMat = propMat;
}

face3D ScenarioObject::getFaceObjIn3D(int position)
{
    return facesObjIn3D[position];
}

Point3D ScenarioObject::getVectorObjIn3D(int position)
{
    position -= 1;
    pointset = listVectores[position];
    return pointset;

}

propertyMaterial ScenarioObject::getPropertyMaterial()
{
    return propMat;
}

int ScenarioObject::getSizeFaces()
{
    return sizeFaces;
}

int ScenarioObject::getSizeVector()
{
    return sizeVector;
}


Point3D ScenarioObject::getFront()
{
    return front;
}

Point3D ScenarioObject::getBack()
{
    return back;
}

void ScenarioObject::setBack(Point3D value)
{
    back = value;
}

Point3D ScenarioObject::getSideLeft()
{
    return sideLeftm;
}

void ScenarioObject::setSideLeft( Point3D value)
{
    sideLeftm = value;
}

Point3D ScenarioObject::getSideRight()
{
    return sideRight;
}

void ScenarioObject::setSideRight( Point3D value)
{
    sideRight = value;
}

Point3D ScenarioObject::getTop()
{
    return Top;
}

void ScenarioObject::setTop( Point3D value)
{
    Top = value;
}

Point3D ScenarioObject::getDown()
{
    return Down;
}

void ScenarioObject::setDown( Point3D value)
{
    Down = value;
}

void ScenarioObject::setFront(Point3D value)
{
    front = value;
}

Point3D ScenarioObject::getCentroid()
{
    return centroid;
}

void ScenarioObject::setCentroid(Point3D value)
{
    centroid = value;
}

