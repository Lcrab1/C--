#include "cylinder.h"
Cylinder::Cylinder(double a, double b, double r, double h)
    : Circle(a, b, r), height(h)
{
}
Cylinder *Cylinder::Get()
{
    return this;
}
void Cylinder::Set(double h)
{
    height = h;
}
void Cylinder::Show()
{
}
double Cylinder::GetArea()
{
    double r = Circle::GetR();
    return 2 * 3.14 * r * r + 2 * 3.14 * r * height;
}
double Cylinder::GetVolume()
{
    double r = Circle::GetR();
    return 3.14 * r * r * height;
}
string Cylinder::GetName()
{
    return "Cylinder";
}