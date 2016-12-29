#include "mapshadow.h"

MapShadow::MapShadow(vector<ScenarioObject *> *groupScenarioObject)
{
    this->groupScenarioObject = groupScenarioObject;
}

bool MapShadow::findShadow(face3D faceBelongPoint)
{
    return faceFurtherNear->checkIfThereFaceBetweenPointAndLight(faceBelongPoint,
                                                                 groupScenarioObject);
}


