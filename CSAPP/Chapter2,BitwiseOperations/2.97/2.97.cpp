#include <iostream>
using namespace std;
typedef unsigned float_bits;



//
unsigned getBitLength(int i){
    unsigned length = 0;
    while((1<<length)<i){
        length++;
    }
    return length;
}


float_bits float_i2f(int i){
    //sig=1&&rest==0 INT_MIN
    unsigned bias = 0x7f;
    unsigned sig = i >> 31 & 0x1;
    unsigned rest = i & 0x7fffffff;

    unsigned exp;
    unsigned frac;

    if(sig==1&&rest==0){
        exp = bias + 31;
        frac = 0;
        return sig << 31 | exp<< 23;
    }

    //全部转化为正数
    if(i<0){
        i = -i;
    }

    unsigned bitlength = getBitLength(i);
    //bitlength<=24 后23位放到fraction
    if(bitlength<=24){
        exp = bitlength-1;
        frac = (rest & 0x7fffff)<<(23-exp);
        return sig << 32 | exp << 23 | frac;
    }
    //bitlength>24 取高23位 剩下的要舌入
    exp = bitlength - 1;
    frac = (rest & 0x4fffffff) >> (exp - 23);
    //考虑舌入
    unsigned bits = ~(-1 << (exp - 23)) & rest;
    unsigned compare = 1 << (exp - 23);
    
}