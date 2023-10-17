#include"BinaryTree.h"
#include<queue>
#include<string.h>
#define MAX 20
//无参构造函数
template<typename T>
 _BINARYTREENODE_<T>::_BINARYTREENODE_(){leftChild=rightChild=nullptr;}
//给element初始化的构造函数
template<typename T>
_BINARYTREENODE_<T>::_BINARYTREENODE_(const T& theElement)
{
    element=theElement;
    leftChild=rightChild=nullptr;
}
//给element和左右子树均初始化的构造函数
template<typename T>
_BINARYTREENODE_<T>::_BINARYTREENODE_(const T& theElement,_BINARYTREENODE_<T>* theLeftChild,_BINARYTREENODE_<T>* theRightChild)
{
    element=theElement;
    leftChild=theLeftChild;
    rightChild=theRightChild;
}
//访问节点
template<typename T>
void _BINARYTREENODE_<T>::visit(_BINARYTREENODE_<T> *x)
 {//访问节点*x,仅输出element域
    cout<<x->element<<" ";
 }
 //前序遍历 根左右
template<typename T>
void _BINARYTREENODE_<T>::preOrder()
{
    if(this==nullptr){return;}
    visit(this);                   //访问数根
    this->leftChild->preOrder();     //前序遍历左子树
    this->rightChild->preOrder();    //前序遍历右子树

}
//中序遍历  左根右
template<typename T>
void _BINARYTREENODE_<T>::inOrder()
{
    if(this==nullptr){return;}
    this->leftChild->inOrder();     //中序遍历左子树
    visit(this);                   //访问数根
    this->rightChild->inOrder();    //中序遍历右子树
}
//后序遍历  左右根
template<typename T>
void _BINARYTREENODE_<T>::postOrder()
{
    if(this==nullptr){return;}
    this->leftChild->postOrder();     //后序遍历左子树
    this->rightChild->postOrder();    //后序遍历右子树
    visit(this);                   //访问树根
}

//输出完全括号化的中缀表达式
template<typename T>
void _BINARYTREENODE_<T>::infix()
{
    if(this!=nullptr)
    {
        cout<<'(';
        this->leftChild->infix();
        cout<<this->element;
        this->rightChild->infix();
        cout<<')';
    }
}

//层次遍历二叉树
template<typename T>
void _BINARYTREENODE_<T>::levelOrder()
{
    queue<_BINARYTREENODE_<T>*>q;
    while(this!=nullptr)
    {
        //访问当前节点数据域
        visit(this);
        //将当前节点的孩子插入队列
        if(this->leftChild!=nullptr)
            q.push(this->leftChild);
        if(this->rightChild!=nullptr)
            q.push(this->rightChild);
        //提取下一个要访问的节点
        if(q.empty()){return;}
        *this=*q.front();
        q.pop();
    }
}

template<typename T>
//为什么用const char*代替string就不对呢？主要是在比较t->element和parameter1这两个字符串时会出错,不管是==还是strcmp都会错
string test(_BINARYTREENODE_<T>* t,string parameter1){
    if(t == nullptr)
        return "wrong parameter!";
    if(test(t->leftChild,parameter1)==parameter1 || t->element==parameter1 || test(t->rightChild,parameter1)==parameter1)
        return parameter1;
    else
        return "wrong parameter!";
}


int main(){

    _BINARYTREENODE_<string>*t2=new _BINARYTREENODE_<string>("rightChild");
    _BINARYTREENODE_<string>*t4=new _BINARYTREENODE_<string>("test");
    _BINARYTREENODE_<string>*t1=new _BINARYTREENODE_<string>("leftChild",t4,nullptr);
    _BINARYTREENODE_<string>*t3=new _BINARYTREENODE_<string>("+",t1,t2);
    char* String=new char[MAX];
    cin>>String;
    if(test(t3,String)==String){
        cout<<"found "<<String<<" successfully!"<<endl;
    }
    else
    {
        cout<<"fail to find "<<String<<endl;
    }
    cout<<test(t3,String)<<endl;

    cout<<0<<endl;
    cout<<"前序遍历： ";
    t3->preOrder();
    cout<<endl;
    cout<<"中序遍历： ";
    t3->inOrder();
    cout<<endl;
    cout<<"后序遍历： ";
    t3->postOrder();
    cout<<endl;
    cout<<"完全括号化的中缀表达式： ";
    t3->infix();
    cout<<endl;
    cout<<"层序遍历： ";
    t3->levelOrder();
    system("pause");
}