#ifndef FACE3D_H
#define FACE3D_H
#include "point3d.h"
#include "propertymaterial.h"
#include "light.h"

typedef struct {
    Point3D normal, Vertex1, Vertex2, Vertex3, pointInsertFace;
    int idV1, idV2, idV3;
    float red , green, blue;
    bool chosenFaceFlag = false;
    propertyMaterial propMaterial;
    light light0;
}face3D;

#endif // FACE3D_H
