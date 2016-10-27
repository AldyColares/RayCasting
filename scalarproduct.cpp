#include "scalarproduct.h"

ScalarProduct::ScalarProduct()
{

}

vector<float> ScalarProduct::scalarproduct(const vector<float> &V0, const vector<float> &V1)
{
    vector<float> result (V0.size());
        result = V0(0) * V1(0) + V0(1) * V1(1) + V0(1) * V1(1);
        return result;
}
