#include <iostream>
using namespace std;


//1.若有符号字节为负数,packed_t接收的无符号数在此算法下不能够对符号位1进行符号扩展

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    int max_bytenum = 3;
    return (int)word << ((max_bytenum - bytenum) << 3) >> (max_bytenum << 3);
}

void test_unit1()
{
    printf("0xf1a23344->%.2x\r\n", xbyte(0xf1a23344, 0));
    printf("0xf1a2D344->%.2x\r\n", xbyte(0xf1a2D344, 1));
    printf("0xf1a2D344->%.2x\r\n", xbyte(0xf1a2D344, 2));
    printf("0xf1a23344->%.2x\r\n", xbyte(0xf1a23344, 3));

    printf("0xAABBCCDD->%.2x\r\n", xbyte(0xAABBCCDD, 0));
    printf("0xAABBCCDD->%.2x\r\n", xbyte(0xAABBCCDD, 1));
    printf("0xAABBCCDD->%.2x\r\n", xbyte(0xAABBCCDD, 2));
    printf("0xAABBCCDD->%.2x\r\n", xbyte(0xAABBCCDD, 3));
}

int main()
{

    test_unit1();
    system("pause");
}