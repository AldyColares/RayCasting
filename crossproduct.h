#ifndef CROSSPRODUCT_H
#define CROSSPRODUCT_H
#include <vector>



class CrossProduct
{
public:
    CrossProduct();
    float* crossProduct(float V0[3], float V1[3]);
    float* unitVector(float V0[3]);
    ~CrossProduct()
    {

    }

};

#endif // CROSSPRODUCT_H
