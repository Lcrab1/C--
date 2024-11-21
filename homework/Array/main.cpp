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
    cout << "数组大小：" << a.arraySize() << endl;
    cout << "数组a的元素值：";
    for (int i = 0; i < a.arraySize(); ++i)
        cout << a.getElement(i) << " ";
    cout << endl;

    cout << "调整数组a的大小为原来的2倍: " << endl;
    a.resize(a.arraySize() * 2);
    for (int i = 10; i < 20; ++i)
        a.setElement(i, 1 + rand() % 9);
    cout << "调整大小后数组的大小: " << a.arraySize() << endl;

    cout << "用复制构造函数，用数组a初始化b" << endl;
    Array b(a);

    cout << "修改数组a的最后一个元素值为100。" << endl;
    a.setElement(a.arraySize() - 1, 100);
    cout << "数组a的值: ";
    for (int i = 0; i < a.arraySize(); ++i)
        cout << a.getElement(i) << " ";
    cout << endl;

    cout << "数组b的元素值: ";
    for (int i = 0; i < b.arraySize(); ++i)
        cout << b.getElement(i) << " ";
    cout << endl;

    //错误处理测试
    // i=a.getElement(a.arraySize());
    // a.resize(-10);

    cout << "Quit...." << endl;
    system("pause");
    return 0;
}
