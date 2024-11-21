// array.h
#ifndef ARRAY_H
#define ARRAY_H

//错误类型集合，共有三种类型的错误：数组大小错误、内存分配错误和下标越界
enum ErrorType
{
    invalidArraySize,
    memoryAllocationError,
    indexOutOfRange
};

class Array
{
public:
    Array(int sz = 50);                //构造函数
    Array(const Array &a);             //复制构造函数
    ~Array();                          //析构函数
    void setElement(int n, int value); //设置数组下标为n处元素的值为value
    int &getElement(int n);            //取数组下标为n的元素的值
    int arraySize() const;             //返回数组大小（常成员函数知识见第五章课件）
    void resize(int sz);               //动态改变数组的大小
private:
    int *alist;                                          // int类型指针，用于存放动态分配的数组内存首地址
    int size;                                            //数组大小
    void Error(ErrorType error, int badIndex = 0) const; //错误处理函数
};

#endif
