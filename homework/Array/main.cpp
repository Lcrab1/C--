#include <iostream>
#include <ctime>
using namespace std;
#include "array.h"

int main()
{
    Array a(10);
    srand(time(0));

    for (int i = 0; i < 10; ++i)
        a.setElement(i, 1 + rand() % 9);
    cout << "�����С��" << a.arraySize() << endl;
    cout << "����a��Ԫ��ֵ��";
    for (int i = 0; i < a.arraySize(); ++i)
        cout << a.getElement(i) << " ";
    cout << endl;

    cout << "��������a�Ĵ�СΪԭ����2��: " << endl;
    a.resize(a.arraySize() * 2);
    for (int i = 10; i < 20; ++i)
        a.setElement(i, 1 + rand() % 9);
    cout << "������С������Ĵ�С: " << a.arraySize() << endl;

    cout << "�ø��ƹ��캯����������a��ʼ��b" << endl;
    Array b(a);

    cout << "�޸�����a�����һ��Ԫ��ֵΪ100��" << endl;
    a.setElement(a.arraySize() - 1, 100);
    cout << "����a��ֵ: ";
    for (int i = 0; i < a.arraySize(); ++i)
        cout << a.getElement(i) << " ";
    cout << endl;

    cout << "����b��Ԫ��ֵ: ";
    for (int i = 0; i < b.arraySize(); ++i)
        cout << b.getElement(i) << " ";
    cout << endl;

    //���������
    // i=a.getElement(a.arraySize());
    // a.resize(-10);

    cout << "Quit...." << endl;
    system("pause");
    return 0;
}
