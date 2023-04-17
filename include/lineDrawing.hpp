#include "tgaimage.h"
#include "geometry.h"

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

inline void line(Vec2i v0, Vec2i v1, TGAImage& image, TGAColor color)
{
    bool steep = false;
    
    // if steep transpose image
    if(std::abs(v0.x - v1.x) < std::abs(v0.y - v1.y))
    {
        std::swap(v0.x, v0.y);
        std::swap(v1.x, v1.y);
        steep = true;
    }

    // make always x1 & y1 > x0 & y0
    if(v0.x > v1.x)
    {
        std::swap(v0.x, v1.x);
        std::swap(v0.y, v1.y);
    }

    int dx = v1.x - v0.x;
    int dy = v1.y - v0.y;

    int dError = std::abs(dy) * 2;
    int error = 0; // distance to best straight line
    int y = v0.y;

    for(int x = v0.x; x <= v1.x; x++)
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
            y += v1.y > v0.y ? 1 : -1;
            error -= dx * 2;
        }
    }   
}