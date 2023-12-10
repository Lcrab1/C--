#include<iostream>
using namespace std;

int lower_one_mask(int n){
    //获取w位数的方式
    int w = sizeof(int) << 3;
    //强转为unsigned 使用逻辑右移
    return (unsigned)-1 >> (w - n);
}

void test_unit1(){
    printf("n=6->%x\r\n", lower_one_mask(6));
    printf("n=17->%x\r\n", lower_one_mask(17));
    printf("n=32->%x\r\n", lower_one_mask(32));

}

int main(){
    test_unit1();
    system("pause");
}