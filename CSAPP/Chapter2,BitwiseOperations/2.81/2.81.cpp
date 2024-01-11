#include<iostream>
using namespace std;

void test81(int j,int k){
    cout << "pattern A:";
    int x = -1;
    int A = x << k;
    printf("%.8x\r\n", A);
    cout << "pattern B:";
    int B = x << (j + k);
    int help = ~(x << j);
    B = ~(B | help);
    printf("%.8x\r\n", B);
}

void B(int j,int k){
    int x = -1;
    int ret = ~(x << k) << j;
    printf("%.8x", ret);
}

int main(){

    test81(8, 8);
    B(8, 8);
    system("pause");

}