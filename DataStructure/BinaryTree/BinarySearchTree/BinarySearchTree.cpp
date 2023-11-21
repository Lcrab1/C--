#include <iostream>
#include <queue>
using namespace std;

typedef struct _NODE_
{
    _NODE_ *leftChild = nullptr;
    _NODE_ *rightChild = nullptr;
    int data = 0;
} * BNODE, NODE;
void inOrder(BNODE root);
BNODE searchItem(BNODE bt, int key);
BNODE insertBST(BNODE bt, int data);
BNODE initBinarySearchTree(BNODE bt, int numOfNodes);

int main()
{
    int num = 0;
    cout << "请输入二叉搜索树的结点个数:" << endl;
    cin >> num;
    BNODE root = nullptr;
    root = initBinarySearchTree(root, num);
    cout << "层序遍历该二叉搜索树的结果：" << endl;
    inOrder(root);
    system("pause");
    return 0;
}

void inOrder(BNODE root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->leftChild);
    cout << root->data << " ";
    inOrder(root->rightChild);
}

BNODE searchItem(BNODE bt, int key)
{
    if (bt == nullptr || bt->data == key)
    {
        return bt;
    }
    else if (bt->data > key)
    {
        return searchItem(bt->leftChild, key);
    }
    else
    {
        return searchItem(bt->rightChild, key);
    }
}

BNODE insertBST(BNODE bt, int data)
{
    if (bt == nullptr)
    {
        BNODE s = new NODE;
        s->data = data;
        s->leftChild = nullptr;
        s->rightChild = nullptr;
        return s;
    }
    else if (bt->data > data)
    {
        bt->leftChild = insertBST(bt->leftChild, data);
    }
    else
    {
        bt->rightChild = insertBST(bt->rightChild, data);
    }
    return bt;
}

BNODE initBinarySearchTree(BNODE bt, int numOfNodes)
{
    int count = 0;
    while (count < numOfNodes)
    {
        int data = 0;
        cout << "请输入该节点的数据" << endl;
        cin >> data;
        bt = insertBST(bt, data);
        count++;
    }
    return bt;
}