#include <iostream>
using namespace std;
typedef unsigned float_bits;

float_bits float_absval(float_bits f){
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xf;
    unsigned frac = f & 0x7fffff;

    int is_NAN = (exp == 0xff) && (frac & 0xffffffff);
    if(is_NAN){
        return f;
    }else if(sig){
        return ~sig | exp << 23 | frac;
    }
    return f;
}

float_bits float_absval1(float_bits f)
{
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xf;
    unsigned frac = f & 0x7fffff;

    int is_NAN = (exp == 0xff) && (frac & 0xffffffff);
    if (is_NAN)
    {
        return f;
    }
    //直接返回正数即可 正数就是把sig置零
    return 0<<31| exp << 23 | frac;
}