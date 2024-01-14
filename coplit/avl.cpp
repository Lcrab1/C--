#include<iostream>

int allOddBits(int x)
{
    //错误点在于仅仅使用了与运算，在对2 4 6 8位进行与运算之后，还需要检验最后的结果是否是0xaa格式
    // return !!((x & 0xaa) & (x >> 2) & (x >> 4) & (x >> 6));
    return !(((x & 0xaa) & (x >> 8) & (x >> 16) & (x >> 24)) ^ 0xaa);
}

int main(){
    int a = allOddBits(0x7fffffff);

    system("pause");
}