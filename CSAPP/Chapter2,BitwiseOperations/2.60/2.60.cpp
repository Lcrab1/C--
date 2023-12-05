#include<iostream>
using namespace std;

unsigned replace_byte(unsigned x,int i,unsigned char b){
    if(i==0){
        return x & 0xffffff00 | b;
    }else if(i==1){
        return x & 0xffff00ff | b<<8;
    }else if(i==2){
        return x & 0xff00ffff | b << 16;
    }else if(i==3){
        return x & 0x00ffffff | b << 24;
    }
    return 0;
}

int main(){
    int x = 0x12345678;
    char b = 0xAB;
    printf("%x\r\n", replace_byte(x, 0, b));
    printf("%x\r\n", replace_byte(x, 2, b));
    system("pause");
}