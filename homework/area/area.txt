#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14

//圆
double area(double radius)
{
    return PI * radius * radius;
}

//矩形
double area(double a, double b)
{
    return a * b;
}

//三角形
double area(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main()
{
    cout << "圆形的面积：" << area(2) << endl;
    cout << "矩形的面积：" << area(2, 4) << endl;
    cout << "三角形的面积：" << area(3, 4, 5) << endl;
    system("pause");
}