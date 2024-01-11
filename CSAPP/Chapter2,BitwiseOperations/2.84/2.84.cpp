#include <iostream>
using namespace std;

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    // 两个0 正负
    // x小于0，y大于等于0  x小于等于0，y大于0
    // x大于0，y大于等于0  x大于等于0，y大于0
    // x小于0，y小于等于0  x小于等于0，y小于0

    return (ux << 1 == 0 && uy << 1 == 0) ||
           (sx && !sy) ||
           (!sx && !sy && ux <= uy) ||
           (sx && sy && ux >= uy);
}