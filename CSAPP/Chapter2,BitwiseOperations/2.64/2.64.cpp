#include<iostream>
using namespace std;

int any_add_one(unsigned x){
    return !!(x & 0x55555555);
}

int main(){
    cout << any_add_one(0x88818888) << endl;
    cout << any_add_one(0x88888888) << endl;

    system("pause");
}