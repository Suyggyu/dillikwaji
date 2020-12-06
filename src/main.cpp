#include "Image.h"
#include "math.h"

#define MIN(x, y) (x < y) ? x : y
#define MAX(x, y) (x > y) ? x : y

int main(void)
{
    Vec3 black(0, 0, 0), white(255, 255, 255), red(255, 0, 0), green(0, 255, 0), blue(0, 0, 255);

    Image img1;

    img1.LoadPPM("sample.ppm");

    for(int i = img1.GetWidth()/4-1; i < img1.GetWidth()*3/4; i++)
    {
        for(int j = img1.GetWidth()/4-1; j < img1.GetWidth()*3/4; j++)
        {
            img1.PlacePixel(Vec2(i, j), img1.GetPixel(Vec2(i, j))*3/4);
        }
    }

    img1.ExportPPM();

    return 0;
}
