#include <iostream>
#include <limits>
int isAsciiDigit(int x)
{
    //考虑不到高24位
    // int secondNum = (x >> 4&0xf);
    // int isHex1 = !(secondNum^0x3);//精确值
    // int isHex2 = !!((((x & 0xA) ^ 0xA)) | ((x & 0xC) ^ 0xC));   //范围
    // return isHex1 & isHex2;

    int secondNum = (x >> 4);
    int isHex1 = !(secondNum ^ 0x3);                              //精确值
    int isHex2 = (!!(((x & 0xA) ^ 0xA)) & (!!((x & 0xC) ^ 0xC))); //范围
    return isHex1 & isHex2;
}
int conditional(int x, int y, int z)
{
    int a = !!x;
    a = (a << 31) >> 31;
    return (a & y) | (~a & z);
}

int isLessOrEqual(int x, int y)
{
    int int_min = 1 << 31;
    int xisMin = !(x ^ int_min);
    int yisMax = !(y ^ (~int_min));
    int yisNotMin = !!(y ^ int_min);
    int xNotMax = !!(x ^ (~int_min));
    int isEqual = !((x + (~y + 1)) ^ 0);         // x=y时，isEqual为1，否则为0
    int isLess = (((x + (~y + 1)) >> 31) & 0x1); // x<y时 isLess为1 否则为0
    return isEqual | (isLess & xNotMax & yisNotMin) | xisMin | yisMax;
}

unsigned floatScale2(unsigned uf)
{
    unsigned sig = uf >> 31;
    unsigned exp = (uf >> 23) & 0xff;
    unsigned mask = (0x7 << 20) | (0xff << 12) | (0xff << 4) | (0xf);
    unsigned frac = uf & mask;
    unsigned bias = 0x7f;
    int isExpZero = !(exp ^ 0x0);
    int isFracZero = !(frac ^ 0x0);
    // NaN Infi
    unsigned NaN_or_Infi = !(exp ^ 0xff);

    if (NaN_or_Infi)
        return uf;

    // 0
    if (isExpZero && isFracZero)
    {
        return sig << 31;
    }
    // exp==0
    if (isExpZero && (!isFracZero))
    {
        frac <<= 1;
        return sig << 31 | exp << 23 | frac;
    }
    // exp!=0
    exp = exp + 1;
    unsigned res = sig << 31 | exp << 23 | frac;
    return res;
}

int floatFloat2Int(unsigned uf)
{
    unsigned bias = 0x7f;
    unsigned sig = uf >> 31;
    int exp = uf >> 23 & 0xff;
    unsigned frac = uf & 0x7fffff;
    int E = exp - bias;
    unsigned M;
    int num;
    // NaN and Infi
    unsigned NaNorInfi = !(exp ^ 0xff);
    // exp<bias+0 1.xxxxxx  直接返回0

    // bias+23<=exp<bias+31 frac可以完全被移位，并且int不会溢出
    // bias+31<=exp int会溢出
    // bias+0<=exp<bias+23  部分frac可以被移位
    if (NaNorInfi)
    {
        num = 0x80000000u;
    }
    else if (E < 0)
    {
        num = 0;
    }
    else if (E >= 31)
    {
        num = 0x80000000u;
    }
    else
    {
        //相当于1.xxxx直接变成1xxxx 即已经移了23位了
        M = frac | 0x800000;
        if (E >= 23)
        {
            //所以如果E大于23，那么移动的位数不够，还需要再左移E-23位
            num = M << (E - 23);
        }
        else
        {
            //如果E小于23，那么此时移动的多了，还要右移(23-E)位，把多左移的位右移回来
            num = M >> (23 - E);
        }
    }
    if (sig)
    {
        return -num;
    }
    else
    {
        return num;
    }
}
int main()
{
    int x = 0x3f800000;
    int a = floatFloat2Int(x);
    system("pause");
}