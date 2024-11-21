#include <iostream>

class Example
{
private:
    int m_value;

public:
    Example()
    {
        std::cout << "Created Entity!" << std::endl;
    }
    Example(int x)
    {
        std::cout << "Created Entity with " << x << std::endl;
    }
};

class Entity
{
private:
    Example m_Example;

public:
    Entity()
        : m_Example(Example(8))
    {
    }
};

int main()
{
    Entity e0;
    system("pause");
}