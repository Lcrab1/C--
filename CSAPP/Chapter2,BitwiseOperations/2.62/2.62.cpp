#include<iostream>
using namespace std;


bool int_shifts_are_arithmetic(){
    int x = -1;
    int shift_val = sizeof(int) << 3;
    return x>>shift_val && -1;
}


int main(){
    if(int_shifts_are_arithmetic()){
        printf("shifts are arithmetic!\r\n");
    }else{
        printf("shifts are logical!\r\n");
    }

    system("pause");
}