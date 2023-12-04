#include<iostream>
using namespace std;

typedef unsigned char* type_pointer;

void show_byte(type_pointer start,size_t len){
    int i;
    for (i = 0; i < len;i++){
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_short(short x){
    show_byte((type_pointer)&x,sizeof(short));
}

void show_long(long x){
    show_byte((type_pointer)&x, sizeof(long));
}

void show_double(double x){
    show_byte((type_pointer)&x, sizeof(double));
}

int main(){
    short s = 123;
    long l = 123;
    double d = 123.0;
    show_short(s);
    show_long(l);
    show_double(d);
    system("pause");
}