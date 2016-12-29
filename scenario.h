#ifndef SCENARIO_H
#define SCENARIO_H

#include "light.h"
#include "camera.h"
#include "scenarioObject.h"
#include "point3d.h"
#include "gridpixel.h"
#include "loadmaterial.h"
#include  <vector>
#include "light.h"
#include "translationobject.h"
#include "scalerobject.h"
#include "quaternions.h"


class Scenario
{
public:
    Scenario();

    void LoadScenario();

    void setGridPixel(GridPixel *gridPixel);
    void setLight(light lig);
    void setGroupScenarioObje(vector<ScenarioObject*> *groupScenarioObject);

    Camera* getCamera();
    ScenarioObject *getMaterial();
    vector<ScenarioObject*>* getGroupScenarioObject();
    light getLight();
    GridPixel *getGridPixel();


private:
    light light0;
    ScenarioObject *scenarioObje;
    Camera *camera;
    GridPixel *gridPixel;
    LoadMaterial *loadMaterial;
    int sizeMaterial;
    vector<ScenarioObject*>* vectorScenarioObject;
    ScalerObject scalerObject;
    TranslationObject translationObject;
    Quaternions quaternions;

};

#endif // SCENARIO_H
