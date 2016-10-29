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

    setFaceObjIn3D(point3D point3D, int position);
    setVectorObjIn3D(float point[3], int position);

    point3D getFaceObjIn3D(int position);
    face3D getVectorObjIn3D(int position);


private:
    point3D facesObjIn3D[100];
    float listVectores[100][3];
    const int x = 0;
    const int y = 1;
    const int z = 2;


};

#endif // SCENARIOOBJECT_H
