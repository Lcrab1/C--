//判断搜索二叉树
#include<iostream>
using namespace std;
#include<limits>
#include<list>
#include<stack>
class Node
{

    public:
    int value;
    Node* left;
    Node* right;
};

int preValue = INT_MIN;

//左小右大，中序遍历（递归）的结果应该是递增序，新的值应该大于等于旧的值
bool isBST(Node* head)
{
    if(head==nullptr)
    {return true;}
    bool isLeftBst=isBST(head->left);

    if(!isLeftBst){
        return false;
    }
    if(head->value<=preValue){
        return false;
    }else{
        preValue = head->value;
    }
    return isBST(head->right);
}

//利用链表判断是否是搜索二叉树
 void process(Node *head, list<Node*> *inOrderList)
{
    if(head==nullptr)
    {
        return;
    }
    process(head->left, inOrderList);
    inOrderList->push_back(head);
    process(head->right, inOrderList);
}   

bool isBST2(Node *head)
{
    if(head=nullptr)
    {
        return true;
    }
    list<Node*> *inOrderList = new list<Node*>;
    process(head, inOrderList);
    for (list<Node*>::iterator it = inOrderList->begin(); it!= inOrderList->end();++it)
    {
        list<Node*>::iterator next =std::next(it) ;
        if(next!=inOrderList->end()&&(*it)->value>(*next)->value){
            return false;
        }
    }
    return true;
}


//非递归中序遍历判断二叉搜索树
bool isBST3(Node* head)
{
    if(head==nullptr){
        return true;
    }

    int preValue = INT_MIN;
    stack<Node*> *inOrderStack = new stack<Node*>;
    while(!inOrderStack->empty()||head!=nullptr)
    {
        if(head!=nullptr){
            inOrderStack->push(head);
            head = head->left;
        }else{
            head = inOrderStack->top();
            inOrderStack->pop();
            if(head->value<=preValue){
                return false;
            }else{
                preValue = head->value;
            }
            head = head->right;
        }
    }
    return true;
}

