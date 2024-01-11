#include <iostream>
using namespace std;
typedef unsigned float_bits;

//非规格化值 NAN INF 直接返回0x80000000

//规格化值
/*
    1、阶码值>23 肯定可以用整数表示,那么只需要考虑是否会超出int的范围 阶码值不能大于30
    2、阶码值>30 溢出 返回0x80000000
    3、阶码值＜23的情况，需要判断fraction的最后一个1在哪一位(cuo)
*/
//1.xxxx int 最大表示011111111... 2^31-1 故只能左移30位

int float_f2i(float_bits f){
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    unsigned bias = 0x7f;
    int ret;

    int is_NAN_or_INF = (exp == 0xff);
    if(is_NAN_or_INF||exp==0){
        return 0x800000000;
    }

    //阶码值大于30
    if (exp > 30 + bias)
    {
        return 0x80000000;
    }
    //阶码值大于23，小于30
    if (exp > 23 + bias && exp <= 30 + bias)
    {
        ret = sig << 31 | frac << 8;
        return ret;
    }
    //阶码值小于23  
}


int float_f2i_anwser(float_bits f){
    //exp: 0~bias 都小于1 结果取0
    //exp: >=31+bias int会溢出 
    //exp: >23+bias && <31+bias frac全部会可以被左移
    //exp: <23+bias frac部分被左移
    unsigned sig=f>>31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    unsigned bias = 0x7f;

    int num;
    unsigned E;
    unsigned M;

    if(exp>=0&&exp<0+bias){
        num = 0;
    }else if(exp>=31+bias){
        num = 0x80000000;
    }else{
        E = exp - bias;
        M = frac | 0x8000000;
        if(E>23){
            num = M << (E - 23);
        }else{
            num = M >> (23 - E);
        }
    }
    return sig ? -num : num;
}
