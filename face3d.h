#ifndef FACE3D_H
#define FACE3D_H
#include "point3d.h"

struct face3D
    {
        point3D v1,v2,v3,normal;
        //the values above are 0,..., 255.
        int red, blue, green;
    };

#endif // FACE3D_H
