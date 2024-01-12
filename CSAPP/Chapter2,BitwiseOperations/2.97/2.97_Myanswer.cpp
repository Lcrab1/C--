#include <stdio.h>
#include <assert.h>
#include <limits.h>
typedef unsigned float_bits;

unsigned getBitLength(int i){
    if((i&INT_MIN)!=0){
        return 32;
    }
    unsigned length = 0;
    while(i<(1<<length)){
        length++;
    }
    return length;
}

unsigned getMask(unsigned length){
    return -1 >> (32 - length);
}

//计算整数转浮点数
float_bits float_i2f(int i){
    //整体思想是对绝对值进行操作，因为负数直接转浮点数，比较困难，因为整数的负数是补码，符号位不是仅仅表示正负号，而浮点数的符号位仅仅是表示符号位

    //分三类情况
    //i=0
    unsigned sig, exp, frac, rest, exp_frac,round_part;
    unsigned bias = 0x7F;
    if(i==0){
        sig = 0;
        exp_frac = 0;
        return sig|exp_frac;
    }
    //i=INT_MIN
    if(i==INT_MIN){
        sig = 1;
        exp = bias + 31;

        return sig | exp << 23 | frac;
    }
    if(i<0){
        sig = 1;
        i = -i;
    }

    //i 但是要分i的位长度与frac的关系
    unsigned bitLength, fbitLength;
    bitLength = getBitLength(i);
    fbitLength = bitLength - 1;
    exp = bias + fbitLength;

    rest = i & getMask(fbitLength);

    if (fbitLength <= 23){
        frac = rest << (23 - fbitLength);
        exp_frac = exp << 23 | frac;
        return sig | exp_frac;  
    }
    else
    {
        unsigned offset = fbitLength - 23;
        unsigned round_mid = 1 << (offset - 1);
        //获取舌入部分，获取fraction
        unsigned round_part = rest & getMask(offset);
        frac = rest >> offset;
        exp_frac = exp << 23 | frac;
        //考虑舌入
        if(round_part<round_mid){

        }else if(round_part>round_mid){
            exp_frac += 1;
        }else{
            //round_part==round_mid 向偶数舌入
            if((exp_frac&0x1)==1){
                exp_frac += 1;
            }
        }
        return sig | exp_frac;
    }
}