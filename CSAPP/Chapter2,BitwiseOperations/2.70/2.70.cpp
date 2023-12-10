#include<iostream>
using namespace std;

int fits_bits(int x,int n){
    int w = sizeof(int) << 3;
    int offset = w - n;
    return (x << offset >> offset) == x;
}

void unit_test1(){
    //题目说的是0xff这个正数能否被8位二进制补码表示，这当然不可以，因为8位二进制补码能表示的最大正数仅有7位，所以输出结果为wrong很正常
    if (fits_bits(0xff,8)){
        printf("0xff and 8 is correct\r\n");
    }else{
        printf("0xff and 8 is wrong\r\n");
    }

    if (fits_bits(0xff, 9))
    {
        printf("0xff and 9 is correct\r\n");
    }else
    {
        printf("0xff and 9 is wrong\r\n");
    }

    if (fits_bits(0b1010, 3))
    {
        printf("0b1010 and 3 is correct\r\n");
    }
    else
    {
        printf("0b1010 and 3 is wrong\r\n");
    }
    
    //此时同0xff 8的情况一致
    if (fits_bits(0b1010, 4))
    {
        printf("0b1010 and 4 is correct\r\n");
    }
    else
    {
        printf("0b1010 and 4 is wrong\r\n");
    }
}

int main(){

    unit_test1();
    system("pause");
}