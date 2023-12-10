#include<iostream>
#include<limits>
using namespace std;

int tsub_ok(int x,int y){
    int sig_mask = INT_MIN;
    //x>0,y<0 x-y<0 positive overflow
    int pos_over = !(x & sig_mask) && (y & sig_mask) && ((x - y) & sig_mask);
    //x<0,y>0 x-y>0 positive overflow
    int neg_over = (x & sig_mask) && !(y & sig_mask) && !((x - y) & sig_mask);
    return !pos_over && !neg_over;
}

void test_unit1(){
    if(tsub_ok(1,5)){
        cout << "x-y does not overflow" << endl;
    }else{
        cout << "x-y does overflow" << endl;
    }

    if (tsub_ok(INT_MAX, -5))
    {
        cout << "x-y does not overflow" << endl;
    }
    else
    {
        cout << "x-y does overflow" << endl;
    }

    if (tsub_ok(INT_MIN, 5))
    {
        cout << "x-y does not overflow" << endl;
    }
    else
    {
        cout << "x-y does overflow" << endl;
    }
}

int main(){

    test_unit1();
    system("pause");

}