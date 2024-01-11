#include <iostream>
using namespace std;
typedef unsigned float_bits;


float_bits float_twice(floate_bits f){
    unsigned bit = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 7fffff;

    int is_NAN = (exp == 0xff) && (frac & 0xffffffff);
    if(is_NAN){
        return f;
    }

    //2*f 
    //fraction<<1
    //DeNormarlized
    if(exp){
        exp = exp + 1;
        //乘二后变为无穷
        is_INF = (exp == 0xff);
        if (is_INF)
        {
            frac = 0;
        }
        return sig | exp << 23 | frac;
    }
    frac = frac << 1;
    return sig<<31 | exp << 23 | frac;

    // exp+1
    // Normarlized
    
}

float_bits float_twice1(floate_bits f)
{
    unsigned bit = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 7fffff;

    int is_NAN_or_INF = (exp == 0xff);
    if (is_NAN_or_INF)
    {
        return f;
    }

    // 2*f

    if (exp)
    {   // exp+1
        // Normarlized
        exp = exp + 1;
        //乘二后变为无穷
        if (exp==0xff)
        {
            frac = 0;
        }
    }

    // fraction<<1
    // DeNormarlized
    frac = frac << 1;
    return sig<<31 | exp << 23 | frac;


}