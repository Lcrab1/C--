#include<iostream>

class String
{
public:
    String() = default;
    String(const char* string)
    {
        std::cout << "Created!" << std::endl;
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
    ~String()
    {
        delete m_Data;
    }
private:
    char *m_Data;
    uint32_t m_Size;
};

class Entity
{
    public:
    Entity(const String&)
    {

    }
};

int main()
{
    Entity entity(String("Cherno"));
    system("pause");
}