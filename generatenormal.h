#ifndef GENERATENORMAL_H
#define GENERATENORMAL_H

struct point3D
    {
        float x, y, z;
    };

class GenerateNormal
{
public:
    GenerateNormal();
    point3D generateVector(point3D v1, point3D v2);

};

#endif // GENERATENORMAL_H
