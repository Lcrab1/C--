#include<iostream>
using namespace std;

int main(){
    //Kx=?
    int x = 1;
    //1.K=17
    x = (x << 4)+x;
    //x=(x<<4+x) 会变成左移五位
    cout << x << endl;
    //2.K=-7
    x = 1;
    x = x-(x<<3);
    cout << x << endl;
    //3.K=60
    x = 1;
    x = (x << 6) - (x << 2);
    cout << x<<endl;
    //4.K=-112
    x = 1;
    x = (x << 4) - (x << 7);
    cout <<x<< endl;

    system("pause");
}