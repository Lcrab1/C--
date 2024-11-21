#include <iostream>
#include <string>
using namespace std;
#include "array.h"

//错误信息
string errorMsg[] = {
    "Invalid array size",
    "Memory allocation error",
    "Invalid index: "};

//错误处理函数
void Array::Error(ErrorType error, int badIndex) const
{
    cout << errorMsg[error]; //根据错误类型，输出相应错误信息
    if (error == indexOutOfRange)
        cout << badIndex; //如果是下标越界错误，输出错误的下标值
    cout << endl;
    exit(-1);
}

//构造函数
Array::Array(int sz)
{
    if (sz <= 0)
        Error(memoryAllocationError);
    int *array = new int[sz];
    size = sz;
    alist = array;
}

//析构函数
Array::~Array()
{
    if (alist != nullptr)
    {
        delete[] alist;
        alist = nullptr;
    }
}

//复制构造函数
Array::Array(const Array &a)
{
    int sz = a.size;
    int *newlist = new int[sz];
    if (newlist == nullptr)
        Error(memoryAllocationError);

    int *srcptr = a.alist;

    int *destptr = newlist;
    for (int i = 0; i < sz; i++)
        *destptr++ = *srcptr++;
    size = sz;
    alist = newlist;
    return;
}

//设置数组下标为n处元素的值为value
void Array::setElement(int n, int value)
{
    //补充相应内容
    if (n < 0 || n >= size) //检查下标是否越界
        Error(indexOutOfRange, n);
    alist[n] = value;
    return;
}

//取数组下标为n的元素的值
int &Array::getElement(int n)
{
    if (n < 0 || n >= size) //检查下标是否越界
        Error(indexOutOfRange, n);
    return alist[n];
}

//返回数组大小
int Array::arraySize() const
{
    //补充相应内容
    return size;
}

//将数组大小修改为sz
void Array::resize(int sz)
{
    if (sz <= 0) //检查是否sz<= 0
        Error(invalidArraySize);
    if (sz == size) //如果size==sz，则退出本函数
        return;

    int *newlist = new int[sz]; //申请新的数组内存
    if (newlist == NULL)        //内存申请是否成功？
        Error(memoryAllocationError);

    int n = (sz <= size) ? sz : size;

    int *srcptr = alist;    //原数组首地址
    int *destptr = newlist; //新数组首地址
    while (n--)
        *destptr++ = *srcptr++; //复制数组元素
    delete[] alist;             //释放原数组所占内存
    alist = newlist;            //使alist指向新数组
    size = sz;                  //更新
}
