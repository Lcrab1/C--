#include<iostream>
using namespace std;

int bitwiseOperation(int x,int y){
    return x & 0x000000ff | y & 0xffffff00;
}

int main(){

    int x = 0x89ABCDEF;
    int y = 0x76543210;
    printf("%x", bitwiseOperation(x, y));
    system("pause");
}

