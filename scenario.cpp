#include "scenario.h"

ScenarioObject scenarioObje;
Camera camera;

Scenario::Scenario(ScenarioObject scenarioObject)
{
    scenarioObje = scenarioObject;

}


void Scenario::LoadScenario()
{
    camera.loadCamera();

}

Camera Scenario::getCamera()
{
    return camera;
}

ScenarioObject Scenario::getMaterial()
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

