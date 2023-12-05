#include<iostream>
using namespace std;

bool questionA(int x){
    return x && -1;
}
bool questionB(int x){
    //不能写return x&&0因为x为0时不执行&&
    return !(~x && 0);
}
bool questionC(int x){
    //获取位移位数
    int shift_val = (sizeof(int) - 1) << 3;
    //获取最低有效位需要左移
    int xleft = x << shift_val;
    //若最低有效字节中的位都为1，则1111 1111，右移shift_val后为-1
    //&&运算符比>>优先级要高
    return (xleft >> shift_val) && -1;
}
bool questionD(int x){
    //若最高有效字节中的位都为0，则0000 0000，左移shift_val位后为0
    int shift_val = (sizeof(int) - 1) << 3;
    int xright = x >> shift_val;
    //注意&& 若左侧为0，则直接返回false
    return !(~(xright << shift_val) && 0);
}

int main()
{
    int x1 = 0xffffffff;
    if(questionA(x1)){
        cout << "A is right!"<<endl;
    }else{
        cout << "A is wrong" << endl;
    }
    int x2 = 0x00000000;
    if (questionB(x2))
    {
        cout << "B is right!" << endl;
    }
    else
    {
        cout << "B is wrong" << endl;
    }
    int x3 = 0x156161ff;
    if (questionC(x3))
    {
        cout << "C is right!" << endl;
    }
    else
    {
        cout << "C is wrong" << endl;
    }
    int x4 = 0x00128389;
    if (questionD(x4))
    {
        cout << "D is right!" << endl;
    }
    else
    {
        cout << "D is wrong" << endl;
    }
    system("pause");
}