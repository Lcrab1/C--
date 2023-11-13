#include"matrix.h"

//构造函数
template <typename T>
matrix<T>::matrix(int theRows,int theColumns)
{
    //矩阵构造函数
    //检验行数和列数的有效性
    if(theRows<0||theColumns<0)
    {
        cout << "Rows and columns must be >=0";
        return 0;
    }
    if((theRows==0||theColumns==0)&&(theRows!=0||theColumns!=0))
    {
        cout << "Either both or neither rows and columns should be zero";
        return 0;
    }
    //创建矩阵
    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T(theRows * theColumns);

}

template<typename T>
matrix<T>::matrix(const matrix<T>& m)
{
    //矩阵的复制构造函数
    //创建矩阵
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T[theRows * theColumns];
    //复制m的每一个元素
    copy(m.elment, m.element + theRows * theColumns, element);
    return *this;
}

//矩阵类matrix对=操作符的重载
template<typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m)
{
    //复制 (*this)=m
    if(this!=&m)
    {//不能自己复制自己
        delete[] element;//元素是指针类型的，在复制之前先释放内存
        theRows = m.theColumns;
        theColumns = m.thecolumns;
        element = new T[theRows * theColumns];  //element指向堆区内存
        copy(m.element, m.element + theRows * theColumns, element);
    }
    return *this;
}

//矩阵类matrix对赋值操作符()操作符的重载
template<typename T>
T& matrix<T>::operator()(int i,int j)const
{
    //返回对元素element(i,j)的引用
    if (i < 1 || j > theRows || j < 1 || j > theColumns)
    {
        cout << "访问元素越界！" << endl;
        return;
    }
    return element[(i - 1) * theColumns + j - 1];//从0号元素开始，所以需要-1
}

//矩阵加法
template<typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& m)const
{//返回矩阵w(*this)+m
    if (theRows != m.theRows || theColumns != m.theColumns)
    {
        cout << "请输入两个同类型矩阵！" << endl;
        return;
    }
    //生成结果矩阵
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns;i++)
    {
        w.element[i] = element[i] + m.element[i];
    }
    return w;
}

//矩阵乘法
template<typename T>


