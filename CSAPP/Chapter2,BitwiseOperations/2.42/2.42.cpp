#include<iostream>
using namespace std;

//返回x/16的值
int div16(int x)
{
    //向右移位是算术移位
    //向右移动31位来判断正负，若为负，则x>>31全为1，若为正，则x>>31全为0
    //与掩码进行与运算，得到偏置量，偏置量bias=除数-1(16-1=15=0xF)
    int bias = (x >> 31) & 0xF;
    return (x + bias) >> 4;
}

    int main()
    {
        int x = 10;
        int y = -17;
        int z = 18;
        cout << div16(x) << " " << div16(y) << " " << div16(z) << endl;
        system("pause");
}