#ifndef _VEC2_H
#define _VEC2_H

#include <cmath>
#include <iostream>

class Vec2
{
public:
    int x, y;
    Vec2();
    Vec2(int x);
    Vec2(int x, int y);

    static double GetDistance(const Vec2& p1, const Vec2& p2);
    friend Vec2 operator+(const Vec2& left, const Vec2& right);
    friend Vec2 operator-(const Vec2& left, const Vec2& right);
    friend Vec2 operator*(const Vec2& left, const Vec2& right);
    friend Vec2 operator/(const Vec2& left, const Vec2& right);
    friend bool operator==(const Vec2& left, const Vec2& right);
    void operator+=(const Vec2& right);
    void operator-=(const Vec2& right);
    void operator*=(const Vec2& right);
    void operator/=(const Vec2& right);
    friend std::ostream& operator<<(std::ostream& os, Vec2 vec);
};

#endif