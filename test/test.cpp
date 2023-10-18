#include<iostream>
#include<tchar.h>
#include "max.h"
#include<string>
using namespace std;
int main(){
   const char* s1="hello";
   const char* s2="hello";
   if(*s2==*s1)
   cout<<"1"<<endl;
   else
   cout<<"0"<<endl;
   if(strcmp(s1,s2)==0)
   cout<<"1"<<endl;
   else
   cout<<"0"<<endl;
   cout << "this is a test"<<endl;
   system("pause");
}