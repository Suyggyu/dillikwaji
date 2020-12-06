#ifndef _VEC3_H
#define _VEC3_H

#include <cmath>
#include <iostream>

class Vec3
{
public:
    int x, y, z;
    Vec3();
    Vec3(int x);
    Vec3(int x, int y, int z);

    static double GetDistance(const Vec3& p1, const Vec3& p2);
    friend Vec3 operator+(const Vec3& left, const Vec3& right);
    friend Vec3 operator-(const Vec3& left, const Vec3& right);
    friend Vec3 operator*(const Vec3& left, const Vec3& right);
    friend Vec3 operator/(const Vec3& left, const Vec3& right);
    friend bool operator==(const Vec3& left, const Vec3& right);
    void operator+=(const Vec3& right);
    void operator-=(const Vec3& right);
    void operator*=(const Vec3& right);
    void operator/=(const Vec3& right);
    friend std::ostream& operator<<(std::ostream& os, Vec3 vec);
};

#endif