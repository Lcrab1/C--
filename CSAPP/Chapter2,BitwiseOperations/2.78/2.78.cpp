#include<iostream>
#include<limits>
using namespace std;

//补码 除法运算的bias=(1<<k)-1 很重要

int divide_power2(int x,int k){
    //判断最高位
    int ret = 0;
    int sig_mask = INT_MIN;
    //最高位为0
    !(x & sig_mask) && (ret=x >> k);
    //最高位为1，需要加上偏置量
    int bias = (1 << k) - 1;
    x &sig_mask && (ret = (x + bias) >> k);
    return ret;
}

int main()
{
    int x = 0x80000007;
    printf("%d=%d\r\n", divide_power2(x, 1), x / 2);
    printf("%d=%d\r\n", divide_power2(x, 2), x / 4);
    int y = 0x70000007;
    printf("%d=%d\r\n", divide_power2(y, 1), y / 2);
    printf("%d=%d\r\n", divide_power2(y, 2), y / 4);

    system("pause");
    return 0;
}