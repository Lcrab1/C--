#include<iostream>
using namespace std;

int main(int argc,char* argv[],char*envp[])
{
    int i;
    printf("Environment variables:\n");
    for (int i = 0; envp[i] != 0;i++){
        printf("envp[%2d]:%s\n", i, envp[i]);
    }
    system("pause");
}