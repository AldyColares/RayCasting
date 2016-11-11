#ifndef FACE3D_H
#define FACE3D_H
#include "point3d.h"

struct face3D
    {
        point3D normal;
        //the values above are 0,..., 255.
        int red, blue, green;
        int idV1, idV2, idV3;
    };

#endif // FACE3D_H
