#include<iostream>

int main(){

    // int x = 10;
    // int *y = &x;
    // int &z = x;

    char x = 10;
    char *y = &x;
    char &z = x;
    std::cout << sizeof(y) << std::endl;
    std::cout << sizeof(z) << std::endl;
}