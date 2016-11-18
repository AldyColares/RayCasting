#include "gridpixel.h"


GridPixel::GridPixel()
{

}

void GridPixel::setColorPixel(int x, int y, Pixel pixel)
{
    this->pixel[x][y] = pixel;
}

Pixel GridPixel::getColorPixel(int x, int y)
{
    return pixel[x][y];

}
