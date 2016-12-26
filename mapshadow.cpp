#include "mapshadow.h"

MapShadow::MapShadow(vector<ScenarioObject *> *groupScenarioObject)
{
    this->groupScenarioObject = groupScenarioObject;
}

bool MapShadow::findShadow(Point3D verticesBetweenPointAndLight)
{
    return faceFurtherNear->checkIfThereFaceBetweenPointAndLight(verticesBetweenPointAndLight,
                                                                 groupScenarioObject);
}


