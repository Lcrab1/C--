#include"AVL.h"

void AVLInsert(NODE **node, int data)
{
    if (*node == nullptr)
    {
        *node = new NODE ;
        (*node)->data = data;
        (*node)->height = 0;
        (*node)->lChild = nullptr;
        (*node)->rChild = nullptr;
    }
    else if (data < (*node)->data)
    {
        AVLInsert(&(*node)->lChild, data);
    }
    else if (data > (*node)->data)
    {
        AVLInsert(&(*node)->rChild, data);
    }
}

void inOrder(NODE ** node){
    if(*node==nullptr){
        return;
    }
    inOrder(&(*node)->lChild);
    cout << (*node)->data<<" ";
    inOrder(&(*node)->rChild);
}