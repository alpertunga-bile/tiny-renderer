#include "tgaimage.h"

inline void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
    bool steep = false;
    
    // if steep transpose image
    if(std::abs(x0 - x1) < std::abs(y0 - y1))
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }

    // make always x1 & y1 > x0 & y0
    if(x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = y1 - y0;

    int dError = std::abs(dy) * 2;
    int error = 0; // distance to best straight line
    int y = y0;

    for(int x = x0; x <= x1; x++)
    {
        if(steep)
        {
            image.set(y, x, color); // detranspose
        }
        else
        {
            image.set(x, y, color);
        }

        error += dError;

        // check if error is greater than one pixel
        if(error > dx)
        {
            y += y1 > y0 ? 1 : -1;
            error -= dx * 2;
        }
    }   
}