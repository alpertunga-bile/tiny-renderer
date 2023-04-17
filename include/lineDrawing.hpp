#include "tgaimage.h"

inline void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
    for(int x = x0; x <= x1; x++)
    {
        float t = static_cast<float>(x - x0) / static_cast<float>(x1 - x0);
        int y = y0 * (1.0f - t) + y1 * t;
        image.set(x, y, color);
    }   
}