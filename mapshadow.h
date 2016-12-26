#ifndef MAPSHADOW_H
#define MAPSHADOW_H
#include "facefurthernear.h"

class MapShadow
{
public:
    MapShadow(vector<ScenarioObject*> *groupScenarioObject);
    bool findShadow(Point3D verticesBetweenPointAndLight);


private:
    vector<ScenarioObject*> *groupScenarioObject;
    FaceFurtherNear* faceFurtherNear = new FaceFurtherNear();

};

#endif // MAPSHADOW_H
