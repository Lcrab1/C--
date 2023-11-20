#include<iostream>
using namespace std;

int getIndex(int *arr,int L,int R){
    int v1 = arr[L];
    while(L<R){
        while(L<R&&arr[R]>=v1){
            R--;
        }
        arr[L] = arr[R];
        while(L<R&&arr[L]<=v1){
            L++;
        }
        arr[R] = arr[L];
    }
    arr[L] = v1;
    return L;
}

void QuickSort(int *arr,int L,int R){
    if(L<R){
        int Index = getIndex(arr, L, R);
        QuickSort(arr, L, Index - 1);
        QuickSort(arr, Index + 1, R);
    }
}