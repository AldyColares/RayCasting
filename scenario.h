#ifndef SCENARIO_H
#define SCENARIO_H
#include "light.h"
#include "camera.h"
#include "scenarioObject.h"
#include "point3d.h"
#include "coordinatetransformation.h"

class Scenario
{
public:
    Scenario(ScenarioObject scenarioObject);
    void LoadScenario();
    light luzpontual0;
    Camera getCamera();
    ScenarioObject getMaterial();

};

#endif // SCENARIO_H
