#include<iostream>
using namespace std;

unsigned srl(unsigned x,int k){
    //算术右移来完成逻辑右移
    unsigned xsra = (int)x >> k;
    int int_bits = sizeof(int) << 3;
    int y = -1;
    //-1的位为1111 1111 1111 1111 左移位数-k位，则前k位全为1，其他位全为0，此时取反，则前k为为0，其他位为1
    int mask = ~(y << (int_bits - k));
    return xsra & mask;
}

int sra(int x,int k){
    //逻辑右移来完成算数右移
    int xsrl = (unsigned)x >> k;
    int int_bits = sizeof(int) << 3;
    int y = 1;
    if((y<<(int_bits-1))&xsrl){
        //最高有效位为1 将右移后的前k位补为1
        int help = -1;
        int mask = help << (int_bits - k);
        return xsrl | mask;
    }
    //最高有效位为0
    return xsrl;
}


int main(){
    //算数->逻辑
    //首位为1
    unsigned x1 = 0xff183900;
    //首位为0
    unsigned x2 = 0x0183900f;
    printf("%.8x\r\n",srl(x1, 8));
    printf("%.8x\r\n", srl(x2, 8));
    //逻辑->算数
    printf("%.8x\r\n", sra(x1, 8));
    printf("%.8x\r\n", sra(x2, 8));
    system("pause");
}