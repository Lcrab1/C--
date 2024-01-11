#include<iostream>
using namespace std;
typedef unsigned float_bits;


float_bits float_negate(float_bits f){
    //exp 11111111 255
    unsigned exp = f >> 23 & 0xff;
    //fraction !=0
    unsigned frac = f & 0x7fffff;
    //NaN
    if(exp==255&&frac!=0){
        return f;
    }
    //s
    if(f>>31&0x1==1){
        return f & 0x7fffffff;
    }else{
        return f | 0x80000000;
    }
    //-f
}


float_bits float_negate1(float_bits f)
{
    //无符号 逻辑右移
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    int is_NAN = (exp == 0xff) && (frac & 0xffffffff);
    if(is_NAN){
        return f;
    }
    return ~sig << 31 | exp << 23 | frac;
}

int main(){


}
