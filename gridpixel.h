#ifndef GRIDPIXEL_H
#define GRIDPIXEL_H
#include "pixel.h"

class GridPixel
{
public:
    GridPixel();
    void setColorPixel(int x, int y, Pixel pixel);
    Pixel getColorPixel(int x, int y);
    Pixel pixel[600][600];


private:

};

#endif // GRIDPIXEL_H
