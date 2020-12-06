#include "Vec3.h"

Vec3::Vec3()
: x(0), y(0), z(0)
{}

Vec3::Vec3(int x)
: x(x), y(x), z(x)
{}

Vec3::Vec3(int x, int y, int z)
: x(x), y(y), z(z)
{}

double Vec3::GetDistance(const Vec3& p1, const Vec3& p2)
{
    return sqrt(pow((double)(p1.x - p2.x), 2.0) + pow((double)(p1.y - p2.y), 2.0) + pow((double)(p1.z - p2.z), 2.0));
}

Vec3 operator+(const Vec3& left, const Vec3& right)
{
    return Vec3(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vec3 operator-(const Vec3& left, const Vec3& right)
{
    return Vec3(left.x - right.x, left.y - right.y, left.z - right.z);
}

Vec3 operator*(const Vec3& left, const Vec3& right)
{
    return Vec3(left.x * right.x, left.y * right.y, left.z * right.z);
}

Vec3 operator/(const Vec3& left, const Vec3& right)
{
    return Vec3(left.x / right.x, left.y / right.y, left.z / right.z);
}

bool operator==(const Vec3& left, const Vec3& right)
{
    if(left.x == right.x && left.y == right.y && left.z == right.z)
        return true;
    return false;
}

void Vec3::operator+=(const Vec3& right)
{
    x += right.x;
    y += right.y;
    z += right.z;
}

void Vec3::operator-=(const Vec3& right)
{
    x -= right.x;
    y -= right.y;
    z -= right.z;
}

void Vec3::operator*=(const Vec3& right)
{
    x *= right.x;
    y *= right.y;
    z *= right.z;
}

void Vec3::operator/=(const Vec3& right)
{
    x /= right.x;
    y /= right.y;
    z /= right.z;
}

std::ostream& operator<<(std::ostream& os, Vec3 vec)
{
    os << "Vec3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}