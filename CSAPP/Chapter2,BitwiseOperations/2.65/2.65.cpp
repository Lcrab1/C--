#include<iostream>
using namespace std;

int odd_ones(unsigned x){
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x&1;
}

int main(){
    if(odd_ones(0xC8)){
        cout << "x contains an odd number of 1s" << endl;
    }else{
        cout << "x contains an even number of 1s" << endl;
    }

    if (odd_ones(0xCC))
    {
        cout << "x contains an odd number of 1s" << endl;
    }
    else
    {
        cout << "x contains an even number of 1s" << endl;
    }
    system("pause");
}