#include"BinaryTree.h"
#include<queue>
#include<string.h>
#include<stack>
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
    _BINARYTREENODE_<T>* cur=this;
    queue<_BINARYTREENODE_<T>*>q;
    while(cur!=nullptr)
    {
        //访问当前节点数据域
        visit(cur);
        //将当前节点的孩子插入队列
        if(cur->leftChild!=nullptr)
            q.push(cur->leftChild);
        if(cur->rightChild!=nullptr)
            q.push(cur->rightChild);
        //提取下一个要访问的节点
        if(q.empty()){break;}
        cur=q.front();
        q.pop();
    }
}

//按值查找
template<typename T>
//为什么用const char*代替string就不对呢？主要是在比较t->element和parameter1这两个字符串时会出错,不管是==还是strcmp都会错
const char* _BINARYTREENODE_<T>::searchWithValue(const char* parameter1){
    if(this == nullptr)
        return "wrong parameter!";
    if(this->leftChild->searchWithValue(parameter1)==parameter1 || strcmp(this->element,parameter1)==0 || this->rightChild->searchWithValue(parameter1)==parameter1)
        return parameter1;
    else
        return "wrong parameter!";
}
//求树的深度
template<typename T>
int _BINARYTREENODE_<T>::deep()
{
    if(this==nullptr){return 0;}
    int deepleft=1;
    int deepright=1;
    if(this->leftChild!=nullptr){
        deepleft+=this->leftChild->deep();
    }
    if(this->rightChild!=nullptr){
        deepright+=this->rightChild->deep();
    }
    return deepleft>deepright?deepleft:deepright;
}

//输出叶子结点
template<typename T>
void _BINARYTREENODE_<T>::printLeaf(){

    if(this->leftChild!=nullptr)
    this->leftChild->printLeaf();
    if(this->rightChild!=nullptr)
    this->rightChild->printLeaf();
    if(this->leftChild==nullptr&&this->rightChild==nullptr)
    cout<<this->element<<"  ";
}

//非递归前序遍历
template<typename T>
void _BINARYTREENODE_<T>::preOrderWithoutR()
{
    stack<_BINARYTREENODE_<T>*>s;   //定义辅助栈
    _BINARYTREENODE_<T>* cur=this;
    while(cur!=nullptr||!s.empty())
    {
        while(cur!=nullptr){
            cout<<cur->element<<"  ";
            s.push(cur);
            cur=cur->leftChild;
        }
        if(!s.empty())
        {
            cur=s.top();
            cur=cur->rightChild;
            s.pop();
        }
    }
    cout<<endl;
}

//非递归中序遍历
template<typename T>
void _BINARYTREENODE_<T>::inOrderWithoutR()
{
    stack<_BINARYTREENODE_<T>*>s;   //定义辅助栈
    _BINARYTREENODE_<T>* cur=this;
    while(cur!=nullptr||!s.empty())
    {
        while(cur!=nullptr){

            s.push(cur);
            cur=cur->leftChild;
        }
        if(!s.empty())
        {
            cur=s.top();
            cout<<cur->element<<"  ";
            cur=cur->rightChild;
            s.pop();
        }
    }
    cout<<endl;
}

//非递归后序遍历
template<typename T>
void _BINARYTREENODE_<T>::postOrderWithoutR()
{
    stack<_BINARYTREENODE_<T>*>s;   //定义辅助栈
    _BINARYTREENODE_<T>* cur=this;
    while(cur!=nullptr||!s.empty())
    {
        while(cur!=nullptr)
        {
            s.push(cur);
            cur=cur->leftChild;
        }
        while(!s.empty()&&s.top()->flag==true)
        {
            cur=s.top();
            cout<<cur->element<<"  ";
            s.pop();
        }
        if(cur==this) break;
        if(!s.empty())
        {
            cur=s.top();
            cur->flag=true;
            cur=cur->rightChild;
        }
    }
    cout<<endl;
}


int main(){

    _BINARYTREENODE_<const char*>*t2=new _BINARYTREENODE_<const char*>("rightChild");
    _BINARYTREENODE_<const char*>*t4=new _BINARYTREENODE_<const char*>("test");
    _BINARYTREENODE_<const char*>*t1=new _BINARYTREENODE_<const char*>("leftChild",t4,nullptr);
    _BINARYTREENODE_<const char*>*t3=new _BINARYTREENODE_<const char*>("+",t1,t2);

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
    cout<<endl;
    cout<<"该树的深度为："<<t3->deep()<<endl;
    cout<<"该树的叶子结点为：";
    t3->printLeaf();
    cout<<endl;
    // cout<<"请输入你要查找的值:"<<endl;
    // char* String=new char[MAX];
    // cin>>String;
    // if(t3->searchWithValue(String)==String){
    //     cout<<"found "<<String<<" successfully!"<<endl;
    // }
    // else
    // {
    //     cout<<"fail to find "<<String<<endl;
    // }
    //cout<<t3->searchWithValue(String)<<endl;
    cout<<"非递归前序遍历：";
    t3->preOrderWithoutR();
    cout<<"非递归中序遍历：";
    t3->inOrderWithoutR();
    cout<<"非递归后序遍历：";
    t3->postOrderWithoutR();
    system("pause");
}