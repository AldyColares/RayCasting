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

