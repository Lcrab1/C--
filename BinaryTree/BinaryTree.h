#include<iostream>
using namespace std;

template<class T>
struct _BINARYTREENODE_
{
    T element;
    _BINARYTREENODE_<T>* leftChild;
    _BINARYTREENODE_<T>* rightChild;
    //空实现
    _BINARYTREENODE_();
    //给element赋值
    _BINARYTREENODE_(const T& theElement);
    //给element,leftChild,rightChild都初始化
    _BINARYTREENODE_(const T& theElement,_BINARYTREENODE_* theLeftChild,_BINARYTREENODE_* theRightChild);

    //前序遍历
    void preOrder();
    //中序遍历
    void inOrder();
    //后序遍历
    void postOrder();

    //访问函数
    void visit(_BINARYTREENODE_<T> *x);
    //输出完全括号化的中缀表达式
    void infix();
    //层次遍历
    void levelOrder();
};