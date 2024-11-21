#include <iostream>
#include <string>
using namespace std;
#include "array.h"

//������Ϣ
string errorMsg[] = {
    "Invalid array size",
    "Memory allocation error",
    "Invalid index: "};

//��������
void Array::Error(ErrorType error, int badIndex) const
{
    cout << errorMsg[error]; //���ݴ������ͣ������Ӧ������Ϣ
    if (error == indexOutOfRange)
        cout << badIndex; //������±�Խ��������������±�ֵ
    cout << endl;
    exit(-1);
}

//���캯��
Array::Array(int sz)
{
    if (sz <= 0)
        Error(memoryAllocationError);
    int *array = new int[sz];
    size = sz;
    alist = array;
}

//��������
Array::~Array()
{
    if (alist != nullptr)
    {
        delete[] alist;
        alist = nullptr;
    }
}

//���ƹ��캯��
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

//���������±�Ϊn��Ԫ�ص�ֵΪvalue
void Array::setElement(int n, int value)
{
    //������Ӧ����
    if (n < 0 || n >= size) //����±��Ƿ�Խ��
        Error(indexOutOfRange, n);
    alist[n] = value;
    return;
}

//ȡ�����±�Ϊn��Ԫ�ص�ֵ
int &Array::getElement(int n)
{
    if (n < 0 || n >= size) //����±��Ƿ�Խ��
        Error(indexOutOfRange, n);
    return alist[n];
}

//���������С
int Array::arraySize() const
{
    //������Ӧ����
    return size;
}

//�������С�޸�Ϊsz
void Array::resize(int sz)
{
    if (sz <= 0) //����Ƿ�sz<= 0
        Error(invalidArraySize);
    if (sz == size) //���size==sz�����˳�������
        return;

    int *newlist = new int[sz]; //�����µ������ڴ�
    if (newlist == NULL)        //�ڴ������Ƿ�ɹ���
        Error(memoryAllocationError);

    int n = (sz <= size) ? sz : size;

    int *srcptr = alist;    //ԭ�����׵�ַ
    int *destptr = newlist; //�������׵�ַ
    while (n--)
        *destptr++ = *srcptr++; //��������Ԫ��
    delete[] alist;             //�ͷ�ԭ������ռ�ڴ�
    alist = newlist;            //ʹalistָ��������
    size = sz;                  //����
}
