#ifndef _IMAGE_H
#define _IMAGE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "math.h"

class Image
{
    const char* name;
    int width, height;
    unsigned char** data;
public:
    static char luminosity[];

    void Init(void);
    Image();
    Image(const char* filename, int width, int height);
    ~Image();

    void PlacePixel(const Vec2& position, const Vec3& color);
    void PlaceCircle(const Vec2& center, int radius, const Vec3& color);
    void PlaceRect(const Vec2& p1, const Vec2& p2, const Vec3& color);
    void ExportPPM(void) const;
    void ExportASCII(FILE* stream) const;
    void LoadPPM(const char* filename);
    inline const char* GetName(void) const { return name; };
    inline int GetWidth(void) const { return width; };
    inline int GetHeight(void) const { return height; };
    inline Vec3 GetPixel(const Vec2& position) const { return Vec3(data[position.y*width+position.x][0], data[position.y*width+position.x][1], data[position.y*width+position.x][2]); };
};

#endif