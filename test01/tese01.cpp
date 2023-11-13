#include <iostream>
#include <tchar.h>

using namespace std;

class MyClass;
MyClass Sub_1();
class MyClass
{
public:
    MyClass()
    {

        _tprintf(_T("MyClass()\r\n"));
        m_v1 = new int;
        *m_v1 = 10;
    }
    MyClass(int)
    {
    }
    MyClass(MyClass &Object)
    {

        _tprintf(_T("MyClass(MyClass& Object)\r\n"));
        m_v1 = new int;

        *m_v1 = *(Object.m_v1); // copy
    }
    MyClass(MyClass &&Object)
    {
        _tprintf(_T("MyClass(MyClass&& Object)\r\n"));
        int v1 = 10;
        this->m_v1 = Object.m_v1; // move  为了延长 临时对象中的资源
        Object.m_v1 = NULL;
    }
    MyClass &operator=(MyClass &Object)
    {
        _tprintf(_T("MyClass(MyClass && Object)\r\n"));

        m_v1 = new int;

        *m_v1 = *(Object.m_v1); // copy

        return *this;
    }
    MyClass &operator=(MyClass &&Object)
    {
        _tprintf(_T("MyClass&  operator = (MyClass&& Object)\r\n"));
        int v1 = 10;
        this->m_v1 = Object.m_v1; // move  为了延长 临时对象中的资源
        Object.m_v1 = NULL;
        return *this;
    }
    ~MyClass()
    {
        _tprintf(_T("~MyClass()\r\n"));
        if (this->m_v1 != NULL)
        {
            delete this->m_v1;
            _tprintf(_T("delete this->m_v1\r\n"));
        }
    }

protected:
private:
    int *m_v1 = NULL;
};

MyClass Sub_1()
{
    // MyClass Object;
    // return Object; //关键点1

     return MyClass();     //关键点2
}
int _tmain()
{

    // MyClass v1;
    // MyClass v2(v1);

    MyClass v3 = Sub_1(); //关键点1

    // MyClass v4; //关键点2
    // v4 = Sub_1();
    system("pause");
}