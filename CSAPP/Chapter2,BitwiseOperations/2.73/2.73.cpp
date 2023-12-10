#include<iostream>
#include<limits>
using namespace std;



int saturating_add(int x,int y){
    int sum = x + y;
    int sig_mask = INT_MIN;

    //不使用相对比较运算符来进行 >0  <0 的判断
    int pos_over = !(x & sig_mask) && !(y & sig_mask) && ((x + y) & sig_mask);
    int neg_over = (x & sig_mask) && (y & sig_mask) && !((x + y) & sig_mask);

    //选择 赋值语句  &&前表达式为0，才会进一步执行之后的语句,再加上或运算，起到了选择作用
    //同时注意 逻辑判断的某一个条件也可以时赋值语句
    (pos_over && (sum = INT_MAX)) || (neg_over && (sum = INT_MIN));

    return sum;
}

void test_unit1(){
    printf("INT_MAX=%d\r\n", saturating_add(INT_MAX,50));
    printf("INT_MAX=%d\r\n", INT_MAX );
    printf("INT_MIN=%d\r\n", saturating_add(INT_MIN, -50));
    printf("INT_MIN=%d\r\n", INT_MIN );
}

int main(){

    test_unit1();
    system("pause");
}