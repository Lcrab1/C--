#include<iostream>
using namespace std;

unsigned rotate_left(unsigned x,int n){
    int w = sizeof(int) << 3;
    return (x << n) | (x >> (w - n -1) >> 1);
}


void unit_test1(){{
        printf("n=0->%x\r\n", rotate_left(0x12345678, 0));
        printf("n=4->%x\r\n", rotate_left(0x12345678, 4));
        printf("n=20->%x\r\n", rotate_left(0x12345678, 20));
}}

int main(){
    unit_test1();
    system("pause");
}