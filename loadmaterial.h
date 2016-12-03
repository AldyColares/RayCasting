#ifndef LOADMATERIAL_H
#define LOADMATERIAL_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "scenarioObject.h"
#include "crossproduct.h"
#include "dot.h"
#include "generatevetor.h"
#include "face3d.h"
#include "scenarioObject.h"
#include "propertymaterial.h"
#include "point3d.h"

using namespace std;

class LoadMaterial
{
public:
     LoadMaterial();
     vector<ScenarioObject*> *loadObject();
     void testOnjectt(ScenarioObject *scenarioObject);

private:
     ScenarioObject* scenarioObject;
     Dot dot;
     CrossProduct crossProduct;
     GenerateVetor genevetor;
     propertyMaterial propMat;
     ScenarioObject *insertVectorFaces(std::ifstream& infile);
     Point3D calculatingNormal(face3D vectorsFace, ScenarioObject *sceOnj);
     const int v1 = 0;
     const int v2 = 1;
     const int v3 = 2;
     const int normal = 3;
     float aux;
     Point3D auxPoint3d;


     vector<ScenarioObject*> *vectorScenarioObject;

};

#endif // LOADMATERIAL_H
