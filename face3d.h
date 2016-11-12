#ifndef FACE3D_H
#define FACE3D_H
#include "point3d.h"

struct face3D
    {
        point3D normal, Vector1, Vector2, Vector3;
        int idV1, idV2, idV3;
        bool chosenFaceFlag = false;
        //the values above are 0,..., 255.
        int red, blue, green;
    };

#endif // FACE3D_H
