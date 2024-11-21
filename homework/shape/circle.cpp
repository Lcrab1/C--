#include "circle.h"

Circle::Circle(double a, double b, double r)
    : Point(a, b), radius(r)
{
}

Circle *Circle::Get()
{
    return this;
}
double Circle::GetR()
{
    return radius;
}

void Circle::Set(double r)
{
    radius = r;
}
void Circle::Show()
{
    std::cout << "Circle@[" << GetX() << "," << GetY() << "]"
              << "r=" << radius << std::endl;
}
double Circle::GetArea()
{
    return 3.14 * radius * radius;
}
double Circle::GetPerimeter()
{
    return 2 * 3.14 * radius;
}
string Circle::GetName()
{
    return "Circle";
}