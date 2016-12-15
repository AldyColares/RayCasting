#define EPSILON 0.000001
#include "intertriangle.h"

Intertriangle::Intertriangle()
{

}
//Point3D O é a origem do raio
//Point3D D é o vetor da direção do raio
//V1, V2 e V3 são os vertices do triagulo
bool Intertriangle::intersecao(const Point3D V1, const Point3D V2, const Point3D V3, const Point3D O, const Point3D D){
    Point3D a1, a2;
    Point3D P, T, Q;
    float det, inv_det, u, v, t;

    a1.x = V2.x - V1.x;
    a1.y = V2.y - V1.y;
    a1.z = V2.z - V1.z;

    a2.x = V3.x - V1.x;
    a2.y = V3.y - V1.y;
    a2.z = V3.z - V1.z;


    P = crossProduct.crossProduct(D, a2);
    det = dot.scalarproduct(a1, P);

    if(det > -EPSILON && det < EPSILON)
        return false;
    inv_det = 1/det;
    //Point3D T será a reta do V1 até a origem.
    T.x = O.x - V1.x;
    T.y = O.y - V1.y;
    T.z = O.z - V1.z;

    u = dot.scalarproduct(T, P)*inv_det;

    if(u<0||u>1)
        return false;
    Q = crossProduct.crossProduct(T, a1);

    v = dot.scalarproduct(D, Q)*inv_det;

    if(v<0||v+u>1)
        return false;
    t = dot.scalarproduct(a2, Q)*inv_det;

    if(t>EPSILON)
        return true;
    else
        return false;

}
