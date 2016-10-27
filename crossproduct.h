#ifndef CROSSPRODUCT_H
#define CROSSPRODUCT_H
#include <vector>



class CrossProduct
{
public:
    CrossProduct();
    virtual vector<float> crossProduct(vector<float> const &V0, vector<float> const &V1);
    virtual ~CrossProduct()
    {
    }

    }
};

#endif // CROSSPRODUCT_H
