#ifndef INTERTRIANGLE_H
#define INTERTRIANGLE_H

#include <stdio.h>
#include <stdlib.h>
#include "crossproduct.h"
#include "dot.h"
#include "point3d.h"

using namespace std;

class Intertriangle
{
public:
	Intertriangle();
	bool intersecao(const Point3D V1, const Point3D V2, const Point3D V3, const Point3D O, const Point3D D);

private:
     Dot dot;
     CrossProduct crossProduct;
};

#endif // INTERTRIANGLE_H
