#include<iostream>
#include<tchar.h>
#include<Windows.h>
using namespace std;

void Sub_1();
int Sub_2();
typedef void (*LPFN_SUB_1)();
typedef int (*LPFN_SUB_2)();

int _cdecl _tmain()
{
    LPFN_SUB_1 v1 = nullptr;
    v1 = Sub_1;
    v1();
    LPFN_SUB_2 v2 = nullptr;
    v2 = Sub_2;


}