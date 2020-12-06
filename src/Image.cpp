#include "Image.h"
#include <cstdio>

char Image::luminosity[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

void Image::Init(void)
{
    data = (unsigned char**)malloc(width*height*sizeof(unsigned char*));

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            data[y*width+x] = (unsigned char*)malloc(3*sizeof(unsigned char));
            data[y*width+x][0] = 0;
            data[y*width+x][1] = 0;
            data[y*width+x][2] = 0;
        }
    }
}

Image::Image()
: name("foo"), width(512), height(512)
{
    Init();
}

Image::Image(const char* name, int width, int height)
: name(name), width(width), height(height)
{
    Init();
}

Image::~Image()
{
    free(data);
}

void Image::PlacePixel(const Vec2& position, const Vec3& color)
{
    data[position.y*width+position.x][0] = color.x%256;
    data[position.y*width+position.x][1] = color.y%256;
    data[position.y*width+position.x][2] = color.z%256;
}

void Image::PlaceCircle(const Vec2& center, int radius, const Vec3& color)
{
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            if(Vec2::GetDistance(center, Vec2(x, y)) < radius)
                PlacePixel(Vec2(x, y), color);
        }
    }
}

void Image::PlaceRect(const Vec2& p1, const Vec2& p2, const Vec3& color)
{
    int x_low, x_high, y_low, y_high;

    if(p1.x <= p2.x)
    {
        x_low = p1.x;
        x_high = p2.x;
    }else{
        x_low = p2.x;
        x_high = p1.x;
    }
    if(p1.y <= p2.y)
    {
        y_low = p1.y;
        y_high = p2.y;
    }else{
        y_low = p2.y;
        y_high = p1.y;
    }

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            if(x >= x_low && x <= x_high && y >= y_low && y <= y_high)
                PlacePixel(Vec2(x, y), color);
        }
    }
}

void Image::ExportPPM(void) const
{
    char* filename = (char*)malloc(sizeof(char)*256);
    strcpy(filename, name);
    strcat(filename, ".ppm");

    FILE* out = fopen(filename, "wb");

    fprintf(out, "P6\n%d %d\n255\n", width, height);

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            fwrite(data[y*width+x], 1, 3, out);
        }
    }

    fclose(out);
}

void Image::ExportASCII(FILE* stream) const
{
    Vec3 current_pixel;
    int pixel_grey;
    char* image = (char*)malloc(sizeof(char) * (width+1) * height);

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            current_pixel = GetPixel(Vec2(x, y));
            pixel_grey = (current_pixel.x + current_pixel.y + current_pixel.z)/3;
            image[y*(width+1)+x] = Image::luminosity[(int)(pixel_grey/25.5)];
        }
        image[y*(width+1)+width] = '\n';
    }

    image[(width+1)*height-1] = '\0';
    fprintf(stream, "%s\n", image);
}

void Image::LoadPPM(const char* filename)
{
    FILE* in = fopen(filename, "rb");

    fscanf(in, "P6\n%d %d\n255\n", &width, &height);

    free(data);
    Init();

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            data[width*i+j][0] = fgetc(in);
            data[width*i+j][1] = fgetc(in);
            data[width*i+j][2] = fgetc(in);
        }
    }
}
