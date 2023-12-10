#include<iostream>
using namespace std;

int signed_high_prod(int x,int y){
    int64_t mul = (int64_t)x * y;
    return mul >> 32;
}


unsigned unsigned_high_prod(unsigned x,unsigned y){
    int w=sizeof(int)<<3;
    int sig_x = x >> 31;
    int sig_y = y >> 31;
    int signed_prod = signed_high_prod(x, y);
    return signed_prod + sig_x * y + sig_y * x;
}

unsigned another_unsigned_high_prod(unsigned x,unsigned y){
    int64_t mul = (int64_t)x * y;
    return mul >> 32;
}

int main(){

    unsigned x = 0x12345678;
    unsigned y = 0xFFFFFFFF;
    printf("%x=%x", unsigned_high_prod(x, y), another_unsigned_high_prod(x, y));

    system("pause");
}