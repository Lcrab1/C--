#include<iostream>
using namespace std;

//返回x/16的值
int div16(int x)
{
    return (x < 0 ? x + (1 << 4) - 1 : x) >> 4;
}

int main()
{
    int x = 10;
    int y = -17;
    int z = 18;
    cout << div16(x) << " " << div16(y) << " " << div16(z) << endl;
    system("pause");
}