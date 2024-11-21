#include <iostream>
#include <string>
using namespace std;
#include "point.h"
#include "circle.h"
#include "cylinder.h"
#include "triangle.h"
#include "shape.h"

int main()
{
    Point point(7, 11);
    Circle circle(22, 8, 3.5);
    Cylinder cylinder(10, 10, 3.3, 10);

    Point p1(1, 1), p2(5, 1), p3(1, 4);
    Triangle triangle(&p1, &p2, &p3);

    cout << point.GetName() << ":";
    point.Show();
    cout << "Area = " << point.GetArea();
    cout << " Perimeter = " << point.GetPerimeter();
    cout << " Volume = " << point.GetVolume() << endl
         << endl;

    cout << circle.GetName() << ":";
    circle.Show();
    cout << "Area = " << circle.GetArea();
    cout << " Perimeter = " << circle.GetPerimeter();
    cout << " Volume = " << circle.GetVolume() << endl
         << endl;

    cout << cylinder.GetName() << ":";
    cylinder.Show();
    cout << "Area = " << cylinder.GetArea();
    cout << " Perimeter = " << cylinder.GetPerimeter();
    cout << " Volume = " << cylinder.GetVolume() << endl
         << endl;

    cout << triangle.GetName() << ":";
    triangle.Show();
    cout << "Area = " << triangle.GetArea();
    cout << " Perimeter = " << triangle.GetPerimeter();
    cout << " Volume = " << triangle.GetVolume() << endl
         << endl;

    system("pause");
    return 0;
}
