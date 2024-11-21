#include <iostream>

class Entity
{
private:
    int m_number;

public:
    explicit Entity(int x)
    {
        m_number = x;
        std::cout << m_number << std::endl;
    }
    // Entity(int x)
    // {
    //     m_number = x;
    //     std::cout << m_number << std::endl;
    // }
};
int main()
{

    //  Entity x = 22;
    Entity x(22);
    system("pause");
}