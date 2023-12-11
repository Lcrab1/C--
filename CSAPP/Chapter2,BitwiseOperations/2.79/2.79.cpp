#include<iostream>
#include<limits>
using namespace std;

int divide_power2(int x,int k){
    int is_neg = x & INT_MIN;
    int bias = (1 << k) - 1;
    is_neg && (x = (x + bias));
    return x >> k;
}

int mul3div4_ver1(int x){
    int mul3 = (x << 1) + x;
    return divide_power2(mul3, 2);
}

//先除再乘的结果不对 若能除尽，则结果或许相同，  但若不能除尽，则结果大多不同，所以不要调换乘除的位置

// int mul3div4_ver2(int x){
//     int sig_mask = INT_MIN;
//     int ret = x;
//     //最高位为0时
//     int div_result = ret = x >> 2;
//     !(x & sig_mask) && (ret = (div_result << 1) + div_result);
//     //最高位为1时
//     int bias = (1 << 2) - 1;
//      div_result = (x + bias) >> 2;
//     (x & sig_mask) && (ret = ( div_result<<1)+div_result);
//     return ret;
// }

// int mul3div4_ver3(int x)
// {
//     int sig_mask = INT_MIN;

//     int bias = (1 << 2) - 1;
//     //最高位为1时
//     (x & sig_mask) && (x = x+bias);
//     return ((x>>2)<<1)+(x>>2);
// }

int main(int argc, char *argv[])
{
    int x = 0x87654321;
    printf("%d=%d\r\n", mul3div4_ver1(x), 3 * x / 4);
    // printf("%d=%d\r\n", mul3div4_ver2(x), 3 * x / 4);
    // printf("%d=%d\r\n", mul3div4_ver3(x), 3 * x / 4);
    x = 0x77654321;
    printf("%d=%d\r\n", mul3div4_ver1(x), 3 * x / 4);
    // printf("%d=%d\r\n", mul3div4_ver2(x), 3 * x / 4);
    // printf("%d=%d\r\n", mul3div4_ver3(x), 3 * x / 4);
    system("pause");
    return 0;
}
