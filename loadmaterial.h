#ifndef LOADMATERIAL_H
#define LOADMATERIAL_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "scenarioobject.h"
#include "crossproduct.h"
#include "dot.h"
#include "generatevetor.h"
#include "face3d.h"
#include "scenarioobject.h"


class LoadMaterial
{
public:
     LoadMaterial();
     ScenarioObject loadObject();
     void testOnjectt(ScenarioObject scenarioObject);

private:
     ScenarioObject insertVectorFaces(std::ifstream infile);
     point3D calculatingNormal(point3D vectorsFace[]);
     const int v1 = 0;
     const int v2 = 1;
     const int v3 = 2;
     const int normal = 3;

};

#endif // LOADMATERIAL_H
