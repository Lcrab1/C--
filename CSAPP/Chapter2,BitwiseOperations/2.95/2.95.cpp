#include <iostream>
using namespace std;
typedef unsigned float_bits;

float_bits float_half(float_bits f){
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    unsigned rest = f & 0x7fffffff;

    int is_NAN_or_INF = (exp == 0xff);
    //NAN INF
    if(is_NAN_or_INF){
        return f;
    }

    /*
    浮点数的后两位
    00 >>1  000 2*1/2=1 故halfway为1,此时最后一位为0 直接>>1
    01 >>1  001                     此时最后一位为1，但最低有效位为偶数，直接>>1
    10 >>1  010                     此时最后一位为0，直接>>1  
    11 >>1  011                     此时最后一位为1，但最低有效位为奇数，需要向偶数舌入，对01+1变为01
    */
    int addition = (f & 0x3 == 3);


    if(exp==0){
        // Denormalized frac>>1 但要考虑向偶数舌入的问题
        //
        frac >> 1;
        frac += addition;
    }else if(exp==1){
        // Normalized to Denormalized
        rest >>= 1;
        rest += addition;
        exp = rest >> 23 & 0xff;
        frac = rest & 0x7fffff;
    }else{
        //Normalized
        exp -= 1;
    }
    return sig << 31 | exp << 23 | frac;
 





}