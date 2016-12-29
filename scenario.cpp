#include "scenario.h"

Scenario::Scenario()
{
    scenarioObje = new ScenarioObject();
    camera = new Camera();
    gridPixel = new GridPixel();
    loadMaterial = new LoadMaterial;
}

void Scenario::LoadScenario()
{
    camera->loadCamera();
    light0 = camera->getLigth();
    vectorScenarioObject = loadMaterial->loadObject();

    Point3D point;
    point.x = 0;
    point.y = 20;
    point.z = 0;
   // translationObject.moveObject(vectorScenarioObject->at(0), point);
    Point3D escalar;
    escalar.x = 2.0;
    escalar.y = 2.0;
    escalar.z = 2.0;
    //scalerObject.scaler(escalar, vectorScenarioObject->at(0));
    // sideRight Front Top
    //quaternions.rotation(90,vectorScenarioObject->at(0), "sideRight");

}

Camera* Scenario::getCamera()
{
    return camera;
}

ScenarioObject* Scenario::getMaterial()
{
    return scenarioObje;
}

void Scenario::setGroupScenarioObje(vector<ScenarioObject*> *groupScenarioObject)
{
    vectorScenarioObject = groupScenarioObject;
}

vector<ScenarioObject*> *Scenario::getGroupScenarioObject()
{
    return vectorScenarioObject;
}

void Scenario::setLight(light lig)
{
    light0 = lig;
}

light Scenario::getLight()
{
    return light0;
}

GridPixel* Scenario::getGridPixel()
{
    return gridPixel;
}

void Scenario::setGridPixel(GridPixel* gridPi)
{
    gridPixel = gridPi;
}

