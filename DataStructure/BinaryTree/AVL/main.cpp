#include"AVL.h"
#include<queue>

void test01(){
    NODE *node=nullptr;
    int num;
    cin >> num;
    for (int i = 0; i < num;i++){
        int data;
        cin >> data;
        AVLInsert(&node, data);
    }
    inOrder(&node);
}

int main(){
    test01();
    system("pause");
}