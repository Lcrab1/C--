#include<iostream>
using namespace std;
//wrong version,it doesn't concern rounding
// int threefourths(int x){
//     int bias = (1 << 2)-1;
//     int is_neg = x & INT_MIN;
//     !is_neg &&(x = x -1);
//     return x - (x >> 2);
// }

//right version
int threefourths(int x){
    int is_neg = x & INT_MIN;
    int f = x & ~0x3;
    int l = x & 0x3;
    //前30位先除后乘，不存在舌入问题
    int fd4 = f >> 2;
    int fd4m3 = (fd4 << 1) + fd4;
    //后两位先乘后除，需要考虑舌入问题
    //同时int为有符号数，既然考虑舌入问题，那么就要考虑正负的情况
    int lm3 = (l << 1) + l;
    int bias = (1 << 2) - 1;

    (is_neg) && (lm3 = lm3 + bias);
    int lm3d4 = lm3 >> 2;
    return fd4m3 + lm3d4;   
}

int main(){
    printf("%d=%d\r\n", threefourths(8), 3 * 8 / 4);
    printf("%d=%d\r\n", threefourths(9), 3 * 9 / 4);
    printf("%d=%d\r\n", threefourths(10), 3 * 10 / 4);
    printf("%d=%d\r\n", threefourths(11), 3 * 11 / 4);

    printf("%d=%d\r\n", threefourths(-8), 3 * (-8) / 4);
    printf("%d=%d\r\n", threefourths(-9), 3 * (-9) / 4);
    printf("%d=%d\r\n", threefourths(-10), 3 * (-10) / 4);
    printf("%d=%d\r\n", threefourths(-11), (3 * (-11) / 4));

    printf("%d=%d\r\n", threefourths(0), (3 * (0) / 4));
    printf("%d\r\n", threefourths(INT_MAX));
    printf("%d\r\n", threefourths(INT_MIN));

    system("pause");
}