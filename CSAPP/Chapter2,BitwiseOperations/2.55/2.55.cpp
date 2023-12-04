
#include<iostream>
using namespace std;
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len){
    size_t i;
    for (i = 0; i < len;i++){
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x){
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x){
    show_bytes((byte_pointer)&x, sizeof(void *));
}


int main(){
    int x = 1566;
    float y = 582.3;
    int *p = &x;
    float *p1 = &y;
    show_int(x);
    show_float(y);
    show_pointer(p);
    show_pointer(p1);
    system("pause");
}