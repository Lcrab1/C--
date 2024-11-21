#include "point.h"
Point::Point(double a, double b)
    : x(a), y(b)
{
}

double Point::GetX()
{
    return x;
}
double Point::GetY()
{
    return y;
}
Point *Point::Get()
{
    return this;
}
void Point::Set(double a, double b)
{
    x = a;
    y = b;
}
void Point::Show()
{
    std::cout << "Point[" << x << "," << y << "]" << std::endl;
}
double Point::Distance(const Point &p)
{
    double result = (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    return result > 0 ? sqrt(result) : sqrt(-result);
}
