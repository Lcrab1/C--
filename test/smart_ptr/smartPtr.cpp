#include <iostream>

class SmartPtr
{
public:
    int *m_ptr;

public:
    SmartPtr(int *ptr)
        : m_ptr(ptr)
    {
    }

    ~SmartPtr()
    {
        delete m_ptr;
    }
};

int main()
{
    SmartPtr ptr = new int(5);
    std::cout << *(ptr.m_ptr) << std::endl;
    system("pause");
}

