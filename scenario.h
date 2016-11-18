#ifndef SCENARIO_H
#define SCENARIO_H
#include "light.h"
#include "camera.h"
#include "scenarioObject.h"
#include "point3d.h"
#include "coordinatetransformation.h"
#include "gridpixel.h"
#include "loadmaterial.h"
#include "vector"


class Scenario
{
public:
    light luzpontual0;
    Scenario();

    void LoadScenario();

    void setGridPixel(GridPixel *gridPixel);
    void setLight(light lig);
    Camera* getCamera();
    ScenarioObject *getMaterial();
    light getLigth();
    GridPixel *getGridPixel();


private:
    ScenarioObject *scenarioObje;
    Camera *camera;
    GridPixel *gridPixel;
    LoadMaterial *loadMaterial;
    int sizeMaterial;


};

#endif // SCENARIO_H
