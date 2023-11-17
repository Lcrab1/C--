#include <iostream>
#include <queue>
using namespace std;

typedef struct _NODE_
{
    int value;
    _NODE_ *leftChild;
    _NODE_ *rightChild;
} NODE, *PNODE;


void levelOrder(NODE* head)
{
    if(head==nullptr){
        return;
    }
    queue<NODE *> *Q = new queue<NODE *>;
    Q->push(head);

    while(!Q->empty()){
        head = Q->front();
        Q->pop();
        printf("%d   ", head->value);
        if(head->leftChild!=nullptr){
            Q->push(head->leftChild);
        }
        if(head->rightChild!=nullptr){
            Q->push(head->rightChild);
        }
    }
}