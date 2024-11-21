#ifndef POINT_H
#define POINT_H
#include "shape.h"
class Point : public Shape
{
private:
    double x;
    double y;

public:
    Point(double a, double b);
    double GetX();
    double GetY();
    Point *Get();
    void Set(double a, double b);
    void Show();
    double Distance(const Point &p);
};

#endif