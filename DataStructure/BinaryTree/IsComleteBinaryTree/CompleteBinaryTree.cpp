#include<iostream>
#include<queue>
using namespace std;

typedef struct _NODE_
{
    int value;
    _NODE_ *leftChild;
    _NODE_ *rightChild;
}NODE,*PNODE;

bool isCBT(NODE* head)
{
    if(head==nullptr){
        return true;
    }
    queue<NODE *> *Queue = new queue<NODE *>;  
    //是否遇到过左右孩子不双全的节点
    bool leaf = false;
    NODE* l = nullptr;
    NODE* r = nullptr;
    Queue->push(head);
    while(!Queue->empty())
    {
        head = Queue->front();
        Queue->pop();
        l = head->leftChild;
        r = head->rightChild;
        //如果遇到了叶子结点并且之后的节点不是叶子结点，返回false
        //或者如果该节点不存在右孩子而存在左孩子(不遇到叶子结点也是这样)
        if(leaf&&(l!=nullptr||r!=nullptr)||l==nullptr&&r!=nullptr){
            return false;
        }
        if(l!=nullptr){
            Queue->push(l);
        }
        if(r!=nullptr){
            Queue->push(r);
        }
        //如果遇到了叶子结点（左孩子为空或者右孩子为空）
        if(l==nullptr||r==nullptr){
            leaf = true;
        }
    }
    return true;
}