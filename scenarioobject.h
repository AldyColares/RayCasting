#ifndef SCENARIOOBJECT_H
#define SCENARIOOBJECT_H

struct point3D
    {
        float x, y, z;
    };
struct face3D
    {
    point3D v1,v2,v3,normal;
    };

class ScenarioObject
{
public:
    ScenarioObject();

private:
    face3D facesObjIn3D[100];


};

#endif // SCENARIOOBJECT_H
