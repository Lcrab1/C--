#include<iostream>
#include<limits>
using namespace std;

int main(){

    int min = INT_MIN;
    unsigned x = 1;
    // cout << -min << endl;
    // cout << min << endl;
    cout << -x << endl;
    system("pause");    
}

//1.A不是总为1  x=INT_MIN时，没有对应的相反数
//2.考虑到x+y溢出的情况 假设x+y=128->-128 x=60 y=68 ((x+y)<<4)+y-x=0+68-60=8
//那么 17*y+15*x= 8 -124-124=-248+256=8    //先溢出再求和还是先求和再溢出呢？   结果一样，都是8 因为本质都是对模进行的运算
//B总为1 
//C 总为1 数学原理？(0,1)->(1,0) 1+1=0 ~1=0    (01 01 10 ->01   10 10 00 01
//C的数学原理
/*
    ~x+~y+1=(~x+1)+(~y+1)-1=-x-y-1=-(x+y)-1=~(x+y)+1-1=~(x+y)
*/
//D 总为1  ux=1 uy=2  ux-uy=-1+256=255  y-x=1 -1+256=255
//E总为1 若后两位有数据丢失，则一定变小，若无丢失，则二者相等