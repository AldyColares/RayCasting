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
    light luzpontual0;

    Scenario(ScenarioObject scenarioObject);
    void LoadScenario();
    Camera getCamera();
    ScenarioObject getMaterial();
    void setLight(light lig);
    light getLigth();


};

#endif // SCENARIO_H
