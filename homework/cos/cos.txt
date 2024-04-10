#include <iostream>
#include <cmath>
using namespace std;

double Mycos(double x)
{
    double term = 1, sum = 1;
    int n = 0;
    do
    {
        term *= -x * x / ((2 * n + 1) * (2 * n + 2));
        sum += term;
        n++;
    } while (abs(term) >= 1e-6);
    return sum;
}

int main()
{
    cout << Mycos(1);
    system("pause");
}