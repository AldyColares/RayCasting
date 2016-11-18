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
    scenarioObje = loadMaterial->loadObject();
}

Camera* Scenario::getCamera()
{
    return camera;
}

ScenarioObject* Scenario::getMaterial()
{
    return scenarioObje;
}

void Scenario::setLight(light lig)
{
    luzpontual0 = lig;
}

light Scenario::getLigth()
{
    return luzpontual0;
}

GridPixel* Scenario::getGridPixel()
{
    return gridPixel;
}

void Scenario::setGridPixel(GridPixel* gridPi)
{
    gridPixel = gridPi;
}

