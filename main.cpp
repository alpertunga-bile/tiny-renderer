#include "lineDrawing.hpp"
#include "model.h"

int main()
{
    const char* modelFile = "../models/african_head.obj";
    const char* outputFile = "../output/output_wireframe.tga";
    const TGAColor white = TGAColor(255, 255, 255, 255);
    
    Model* model = new Model(modelFile);

    const int width = 800;
    const int height = 800;

    TGAImage image(width, height, TGAImage::RGB);
    
    for(int i = 0; i < model->nfaces(); i++)
    {
        std::vector<int> face = model->face(i);

        for(int j = 0; j < 3; j++)
        {
            Vec3f v0 = model->vert(face[j]);
            Vec3f v1 = model->vert(face[(j + 1) % 3]);

            int x0 = (v0.x + 1.0f) * static_cast<float>(width) / 2.0f;
            int y0 = (v0.y + 1.0f) * static_cast<float>(height) / 2.0f;
            int x1 = (v1.x + 1.0f) * static_cast<float>(width) / 2.0f;
            int y1 = (v1.y + 1.0f) * static_cast<float>(height) / 2.0f;
            line(x0, y0, x1, y1, image, white);
        }
    }

    image.flip_vertically();
    image.write_tga_file(outputFile);

    delete model;
    
    return 0;
}