#include "lineDrawing.hpp"

int main()
{
    const char* outputFile = "../output/output_line.tga";
    const TGAColor white = TGAColor(255, 255, 255, 255);
    const TGAColor red = TGAColor(255, 0, 0, 255);

    TGAImage image(100, 100, TGAImage::RGB);
    line(13, 20, 80, 40, image, white); 
    line(20, 13, 40, 80, image, red); 
    line(80, 40, 13, 20, image, red);
    image.flip_vertically();
    image.write_tga_file(outputFile);
    
    return 0;
}