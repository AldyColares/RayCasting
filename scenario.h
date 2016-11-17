#ifndef SCENARIO_H
#define SCENARIO_H
#include "light.h"
#include "camera.h"
#include "scenarioObject.h"
#include "point3d.h"
#include "coordinatetransformation.h"
#include "gridpixel.h"
#include "loadmaterial.h"

class Scenario
{
public:
    light luzpontual0;
    Scenario();

    void LoadScenario();

    void setLight(light lig);

    ScenarioObject getObject();
    Camera getCamera();
    ScenarioObject getMaterial();
    light getLigth();
    GridPixel getGridPixel();
    void setGridPixel(GridPixel gridPixel);

private:
    ScenarioObject *scenarioObje;
    Camera *camera;
    GridPixel *gridPixel;
    LoadMaterial *loadMaterial;



};

#endif // SCENARIO_H
