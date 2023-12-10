#include<iostream>
using namespace std;

int int_size_is_32(){
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

void uint_test1(){
    if (int_size_is_32())
    {
        cout << "int size is 32" << endl;
    }
    else
    {
        cout << "int size is not 32" << endl;
    }
}

int int_size_is_32_on_16(){
    // int set_msb = 1 << 15;
    // int beyond_msb1 = set_msb << 15;
    // int beyond_msb2 = beyond_msb1 << 1;
    // int beyond_msb3 = beyond_msb2 << 1;
    // return beyond_msb2 && !beyond_msb3;
    int set_msb=1 << 15 << 15 << 1; // set_msb must > 0
    int beyond_msb = set_msb << 1;
    //beyond must = 0
    return set_msb && !beyond_msb;
}

void uint_test2()
{
    if (int_size_is_32_on_16())
    {
        cout << "int size is 32" << endl;
    }
    else
    {
        cout << "int size is not 32" << endl;
    }
}

int main(){
    uint_test1();
    uint_test2();

    system("pause");
}