#include<iostream>
#include<tchar.h>
#include "max.h"
#include<string>
using namespace std;
int main(){
   // const char* s1="hello";
   // const char* s2="hello";
   // if(*s2==*s1)
   // cout<<"1"<<endl;
   // else
   // cout<<"0"<<endl;
   // if(strcmp(s1,s2)==0)
   // cout<<"1"<<endl;
   // else
   // cout<<"0"<<endl;
   // cout << "this is a test"<<endl;
   // system("pause");

   int v1=10;
   int v2 = 20;
   int &x1 = v1;
   int &x2 = v2;
   x1 ^= x2;
   x2 ^= x1;
   x1 ^= x2;
   cout << v1 << endl;
   cout << v2 << endl;
   cout << x1 << endl;
   cout << x2 << endl;



   system("pause");


}