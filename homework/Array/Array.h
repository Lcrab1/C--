// array.h
#ifndef ARRAY_H
#define ARRAY_H

//�������ͼ��ϣ������������͵Ĵ��������С�����ڴ���������±�Խ��
enum ErrorType
{
    invalidArraySize,
    memoryAllocationError,
    indexOutOfRange
};

class Array
{
public:
    Array(int sz = 50);                //���캯��
    Array(const Array &a);             //���ƹ��캯��
    ~Array();                          //��������
    void setElement(int n, int value); //���������±�Ϊn��Ԫ�ص�ֵΪvalue
    int &getElement(int n);            //ȡ�����±�Ϊn��Ԫ�ص�ֵ
    int arraySize() const;             //���������С������Ա����֪ʶ�������¿μ���
    void resize(int sz);               //��̬�ı�����Ĵ�С
private:
    int *alist;                                          // int����ָ�룬���ڴ�Ŷ�̬����������ڴ��׵�ַ
    int size;                                            //�����С
    void Error(ErrorType error, int badIndex = 0) const; //��������
};

#endif
