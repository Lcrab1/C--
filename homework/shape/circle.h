#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"
class Circle : public Point
{
private:
    double radius;

public:
    Circle(double a, double b, double r);
    Circle *Get();
    double GetR();
    void Set(double r);
    void Show();
    double GetArea();
    double GetPerimeter();
    string GetName();
};

#endif
