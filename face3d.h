#ifndef FACE3D_H
#define FACE3D_H
#include "point3d.h"

typedef struct {
    Point3D normal, Vertex1, Vertex2, Vertex3;
    int idV1, idV2, idV3;
    bool chosenFaceFlag = false;
    //the values above are 0,..., 255.
   // int red, blue, green;
}face3D;

#endif // FACE3D_H
