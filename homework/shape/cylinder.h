#ifndef CYLINDER_H
#define CYLINDER_H
#include"Circle.h"
class Cylinder:public Circle
{
    private:
        double height;

    public:
        Cylinder(double a, double b, double r, double h);
        Cylinder *Get();
        void Set(double h);
        void Show();
        double GetArea();
        double GetVolume();
        string GetName();
};

#endif