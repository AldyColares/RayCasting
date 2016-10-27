#include "crossproduct.h"

CrossProduct::CrossProduct()
{

}

vector<float> CrossProduct::crossProduct(const vector<float> &V0, const vector<float> &V1)
{
    vector<float> result (V0.size());
     result[0] = a[1] * b[2] - a[2] * b[1];
     result[1] = a[2] * b[0] - a[0] * b[2];
     result[2] = a[0] * b[1] - a[1] * b[0];
     return result;
}
