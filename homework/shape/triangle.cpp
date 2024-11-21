#include "triangle.h"

Triangle::Triangle(Point *p1, Point *p2, Point *p3)
    : point1(*p1), point2(*p2), point3(*p3)
{
}
void Triangle::Show()
{
    std::cout << "[<" << point1.GetX() << "," << point1.GetY() << ">,"
              << "<" << point2.GetX() << "," << point2.GetY() << ">,"
              << "<" << point3.GetX() << "," << point3.GetY() << ">]" << std::endl;
}
double Triangle::GetArea()
{
    double a = point1.Distance(point2);
    double b = point1.Distance(point3);
    double c = point2.Distance(point3);
    double s = (a + b + c) / 3.0;
    double result = s * (s - a) * (s - b) * (s - c);
    // 90
    if (result == 0)
    {
        double areas[3] = {a * b, a * c, b * c};
        double min = a * b;
        for (int i = 0; i < 3; i++)
        {
            min = min <= areas[i] ? min : areas[i];
        }
        result = min;
        return result / 2;
    }
    return result > 0 ? sqrt(result) : sqrt(-result);
}
double Triangle::GetPerimeter()
{
    double length1 = point1.Distance(point2);
    double length2 = point1.Distance(point3);
    double length3 = point2.Distance(point3);
    return length1 + length2 + length3;
}
string Triangle::GetName()
{
    return "Triangle";
}