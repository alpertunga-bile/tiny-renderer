#include "wireframe.hpp"

int main()
{
    const char* modelFile = "../models/african_head.obj";
    const char* outputFile = "../output/output_wireframe.tga";
    const TGAColor white = TGAColor(255, 255, 255, 255);
    
    Model* model = new Model(modelFile);

    const int width = 800;
    const int height = 800;

    TGAImage image(width, height, TGAImage::RGB);
    
    renderWireframe(model, width, height, image, white);

    image.flip_vertically();
    image.write_tga_file(outputFile);

    delete model;
    
    return 0;
}