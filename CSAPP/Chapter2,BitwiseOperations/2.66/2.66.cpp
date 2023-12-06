#include<iostream>
using namespace std;

int leftmost_one(unsigned x){
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    x |= x >> 1;
    //后方必须用逻辑与，而不是位与,考虑11100000的情况和00000000的情况
    //x&&1是说，只要x不为0，那么前面的式子就+1
    return (x >> 1) + (x && 1);
}


int main()
{
    printf("0xFF00->0x%x\r\n",leftmost_one(0xFF00));
    printf("0x6600->0x%x\r\n", leftmost_one(0x6600));
    system("pause");
}