#include "Vec2.h"

Vec2::Vec2()
: x(0), y(0)
{}

Vec2::Vec2(int x)
: x(x), y(x)
{}

Vec2::Vec2(int x, int y)
: x(x), y(y)
{}

double Vec2::GetDistance(const Vec2& p1, const Vec2& p2)
{
    return sqrt(pow((double)(p1.x - p2.x), 2.0) + pow((double)(p1.y - p2.y), 2.0));
}

Vec2 operator+(const Vec2& left, const Vec2& right)
{
    return Vec2(left.x + right.x, left.y + right.y);
}

Vec2 operator-(const Vec2& left, const Vec2& right)
{
    return Vec2(left.x - right.x, left.y - right.y);
}

Vec2 operator*(const Vec2& left, const Vec2& right)
{
    return Vec2(left.x * right.x, left.y * right.y);
}

Vec2 operator/(const Vec2& left, const Vec2& right)
{
    return Vec2(left.x / right.x, left.y / right.y);
}

bool operator==(const Vec2& left, const Vec2& right)
{
    if(left.x == right.x && left.y == right.y)
        return true;
    return false;
}

void Vec2::operator+=(const Vec2& right)
{
    x += right.x;
    y += right.y;
}

void Vec2::operator-=(const Vec2& right)
{
    x -= right.x;
    y -= right.y;
}

void Vec2::operator*=(const Vec2& right)
{
    x *= right.x;
    y *= right.y;
}

void Vec2::operator/=(const Vec2& right)
{
    x /= right.x;
    y /= right.y;
}

std::ostream& operator<<(std::ostream& os, Vec2 vec)
{
    os << "Vec2(" << vec.x << ", " << vec.y << ")";
    return os;
}