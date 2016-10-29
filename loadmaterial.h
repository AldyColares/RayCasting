#ifndef LOADMATERIAL_H
#define LOADMATERIAL_H

#include <iostream>
#include <string>
#include "scenarioobject.h"
#include <fstream>
#include "crossproduct.h"
#include "dot.h"

struct point3D
    {
        float x, y, z;
    };
struct face3D
    {
        point3D v1,v2,v3,normal;
    };


class LoadMaterial
{
public:
     LoadMaterial();
     ScenarioObject* loadObject();

private:
     ScenarioObject insertVectorFaces(std::ifstream infile);
     point3D calculatingNormal(point3D vectorsFace[]);
     const int v1 = 0;
     const int v2 = 1;
     const int v3 = 2;
     const int normal = 3;

};

#endif // LOADMATERIAL_H
