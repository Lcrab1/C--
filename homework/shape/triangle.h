#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
#include "Point.h"

class Triangle : public Shape
{
private:
    Point point1;
    Point point2;
    Point point3;

public:
    Triangle(Point *p1, Point *p2, Point *p3);
    void Show();
    double GetArea();
    double GetPerimeter();
    string GetName();
};
#endif
